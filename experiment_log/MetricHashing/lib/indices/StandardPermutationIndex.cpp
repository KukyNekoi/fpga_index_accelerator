//
// Created by Erik Andrés Regla Torres on 3/26/16.
//
#ifndef METRICHASHING_STANDARDPERMUTATIONINDEX_CPP
#define METRICHASHING_STANDARDPERMUTATIONINDEX_CPP
#include "StandardPermutationIndex.h"

template <class T>
StandardPermutationIndex<T>::StandardPermutationIndex(std::size_t size){
    this->pivots_generated = false;
    this->index_used = 0;
    this->pivot_size = 0;
    this->index_size = size;
    this->entries = (std::pair<T, Permutation> *) malloc( this->index_size * sizeof(std::pair<T, Permutation>));
}

template <class T>
void StandardPermutationIndex<T>::get_random_pivots(double factor){
    //Random seed generation for random pivot selection
    long long seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 g1 ((unsigned int)seed1);
    size_t random_pivots_size = factor * (this->index_size < this->index_used ? this->index_size : this->index_used);
    size_t *random_pivots = (size_t*)malloc(sizeof(size_t)*random_pivots_size);
    bool uniform = true;

    while(uniform){
        //Random pivot index generation
        uniform = false;
        for (int i=0; i<random_pivots_size; i++){
            random_pivots[i] = g1() % this->index_used;
        }
        //Randomness checking, normally exits at first iteration
        std::sort(random_pivots, random_pivots + random_pivots_size);
        for (int i=0; i<random_pivots_size-1 && random_pivots_size > 2; i++){
            if(random_pivots[i] == random_pivots[i+1])
                uniform = true;
        }
    }
    this->pivots = random_pivots;
    this->pivot_size = random_pivots_size;
    this->pivots_generated = true;
}

template <class T>
void StandardPermutationIndex<T>::get_forced_sss_pivots(double factor, size_t pivot_amount){
    size_t min_range = pivot_amount;
    size_t max_range = pivot_amount * 1.15;
    double i = 0.0;
    double j = 1.0;
    double alpha = 0.5; //replicating next SSS fixed method /gg
    do{
        this->get_sss_pivots(factor, alpha);
        std::cout << alpha << " recovered=" << this->pivot_size  << "\n";
        if(this->pivot_size > max_range){
            i = alpha;
            alpha = (i + j)/2.0;
        }
        else if(this->pivot_size < min_range){
            j = alpha;
            alpha = (i + j)/2.0;
        }
    }while(this->pivot_size > max_range || this->pivot_size < min_range);
    Log::set_alpha(alpha);
    std::cout << "\n";
}


template <class T>
void StandardPermutationIndex<T>::get_sss_pivots(double factor, double alpha){
    //get samples
    //Random seed generation for random pivot selection
    long long seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    size_t current_index_size = this->index_size < this->index_used ? this->index_size : this->index_used;
    std::minstd_rand0 g1 ((unsigned int)seed1);
    size_t sss_sample_size;
    if(factor == 0.0)
        sss_sample_size = cbrt(this->index_size < this->index_used ? this->index_size : this->index_used);
    else
        sss_sample_size = factor * (this->index_size < this->index_used ? this->index_size : this->index_used);
    size_t *sample = (size_t *) malloc(sizeof(size_t) * sss_sample_size);
    bool uniform = true;
    while(uniform){
        //Random sample index generation
        uniform = false;
        for (int i=0; i < sss_sample_size; i++){
            sample[i] = g1() % this->index_used;
        }
        //Randomness checking, normally exits at first iteration
        std::sort(sample, sample + sss_sample_size);
        for (int i=0; i<sss_sample_size-1 && sss_sample_size > 2; i++){
            if(sample[i] == sample[i+1])
                uniform = true;
        }
    }

    //calculate max distance between the samples (exaustive for now)
    double max_distance = 0;
    for(int i = 0; i < sss_sample_size; i++){
        for(int j = i+1; j < sss_sample_size - 1; j++){
            double dist = entries[sample[i]].first.distance_to(entries[sample[j]].first, this->distance_function);
            if(dist > max_distance)
                max_distance = dist;
        }
    }

    //free memory
    delete [] sample;

//    VARDUMP(max_distance);
    //Insert the first element as pivot
    std::vector<size_t> t_pivots;
    t_pivots.push_back(0);
    // for each new element if distance to all pivots exceeds (max*alpha) add as pivots
    for(int i = 1; i < current_index_size; i++){
        bool accepted = true;
        for(int j = 0; j < t_pivots.size(); j++){
            double dist = entries[i].first.distance_to(entries[t_pivots[j]].first, this->distance_function);
            if(dist < alpha * max_distance){
                accepted = false;
                break;
            }
        }
        if(accepted)
            t_pivots.push_back(i);
    }
    //end
    this->pivot_size = t_pivots.size();
    if(this->pivots_generated)
        free(this->pivots);
    this->pivots = (size_t *) malloc(sizeof(size_t) * this->pivot_size);
    for(int i = 0; i<this->pivot_size; i++)
        this->pivots[i] = t_pivots[i];
    this->pivots_generated = true;
}

template <class T>
Permutation StandardPermutationIndex<T>::get_permutation(T &target){
    Permutation target_permutation(this->pivot_size);
    for(int i=0; i<this->pivot_size; i++)
        target_permutation.permutants[i] = i;
    std::sort(target_permutation.permutants, target_permutation.permutants + this->pivot_size,[&](long & a,long & b){
        return target.distance_to(entries[a].first, distance_function) < target.distance_to(entries[b].first, distance_function);
    });
//    std::cout << "permutation=" << target_permutation.to_string() << "(" ;
//    for(int i=0; i<this->pivot_size; i++)
//        std::cout << target.distance_to(entries[target_permutation.permutation[i]].first, distance_function) << ", ";
//    std::cout << ")\n";
    return target_permutation;
}


template <class T>
size_t* StandardPermutationIndex<T>::query_knn(T target, std::size_t k, double working_quota){

    size_t working_size = (size_t)(working_quota * this->index_used);
    working_size = (k < working_size)? working_size : k;
    size_t *naive_result = this->query_naive_knn(target, working_size);

    //TODO: incremental sorting over the array using IIQS and IQS ?
    std::sort(naive_result, naive_result + working_size, [&](size_t &a, size_t &b){
        return target.distance_to(entries[a].first, distance_function) < target.distance_to(entries[b].first, distance_function);
    });
    //return the results
    size_t *output = (size_t *) malloc(sizeof(size_t) * k);
    for(int i = 0; i < k; i++){
        output[i] = naive_result[i];
    }
    delete [] naive_result;
    return output;
}


template <class T>
size_t* StandardPermutationIndex<T>::query_naive_knn(T target, std::size_t k){
    //compute the permutation for the target
    Permutation target_permutation = get_permutation(target);
    //get permutation distance for every element in the index
    std::pair<size_t, double> *perm_dist = (std::pair<size_t, double> *) malloc(sizeof(std::pair<size_t, double>) * this->index_used );
    for(size_t i=0; i<this->index_used; i++){
        perm_dist[i] = {i, target_permutation.spearman_footrule( this->entries[i].second )};
    }
    //TODO: incremental sorting over the array using IIQS and IQS ?
    std::sort(perm_dist, perm_dist + this->index_used, [&](std::pair<size_t, double> & a,std::pair<size_t, double> & b){
        return a.second < b.second;
    });
    //return the results
    size_t *output = (size_t *) malloc(sizeof(size_t) * k);
    for(int i=0; i<k; i++){
//        std::cout << "IDX= " << i << " OBJECT=" << perm_dist[i].first << "P_DIST=" << perm_dist[i].first << std::endl;
        output[i] = perm_dist[i].first;
    }
//    printf("\nWAITING!");
//    scanf("%d");
    delete [] perm_dist;
    return output;
}

template <class T>
size_t* StandardPermutationIndex<T>::bf_query_knn(T target, std::size_t k){
    //get permutation distance for every element in the index
    size_t *temp = (size_t *) malloc(sizeof(size_t) * this->index_used);
    for(size_t i=0; i<this->index_used; i++){
        temp[i] = i;
    }
//    VARDUMP(this->index_used);
    //TODO: incremental sorting over the array using IIQS and IQS ?
    std::sort(temp, temp + this->index_used, [&](size_t & a, size_t &b){
//        VARDUMP(a);
//        VARDUMP(b);
//        VARDUMP(VectorElement::get_dimension());
        //NOTE: For some reason, if the distance is calculated from _a_ to _target_
        //it returns a bad alloc failure. Dunno why this happens tho.
        double d_a = target.distance_to(this->get(a), this->distance_function);
        double d_b = target.distance_to(this->get(b), this->distance_function);
        return d_a < d_b;
    });
    //return the results
    size_t *output = (size_t *) malloc(sizeof(size_t) * k);
    for(int i=0; i<k; i++){
        output[i] = temp[i];
    }
    delete [] temp;
    return output;
}      //bruteforce methods

template <class T>
size_t* StandardPermutationIndex<T>::bf_query_by_range(T &target, double range, size_t &size){ //bruteforce method two
    size_t count = 0;
    //count every element with lesser distances
    for(size_t i = 0; i<this->index_used; i++){
        if(target.distance_to(this->get(i),this->distance_function) < range){
            count++;
        }
    }

    size_t *temp = (size_t *) malloc(sizeof(size_t) * this->index_used);
    for(size_t i=0; i<this->index_used; i++){
        temp[i] = i;
    }
    //TODO: incremental sorting over the array using IIQS and IQS ?
    std::sort(temp, temp + this->index_used, [&](size_t & a, size_t &b){
        //        VARDUMP(a);
        //        VARDUMP(b);
        //        VARDUMP(VectorElement::get_dimension());
        //NOTE: For some reason, if the distance is calculated from _a_ to _target_
        //it returns a bad alloc failure. Dunno why this happens tho.
        double d_a = target.distance_to(this->get(a), this->distance_function);
        double d_b = target.distance_to(this->get(b), this->distance_function);
        return d_a < d_b;
    });
    //return the results
    size_t *output = (size_t *) malloc(sizeof(size_t) * count);
    for(int i=0; i<count; i++){
        output[i] = temp[i];
    }
    delete [] temp;
    size = count;
    return output;
}

template <class T>
size_t* StandardPermutationIndex<T>::bf_query_hybrid_knn(T &target, std::size_t k, size_t &size){ //bruteforce method two
    size_t *result_stage_1 = this->bf_query_knn(target, k);
    double max_distance = target.distance_to(this->get(result_stage_1[k-1]), this->distance_function);
//    VARDUMP(max_distance);
    return bf_query_by_range(target, max_distance, size);
}

template <class T>
int StandardPermutationIndex<T>::add(T &tgt){
    if(this->index_used >= this->index_size){
        throw "Index space fully used, cannot add new objects to it. :c";
    }
    this->entries[this->index_used] = {tgt, Permutation()};
    this->index_used++;
    return 0;
}

template <class T>
T& StandardPermutationIndex<T>::operator[](const std::size_t idx){
    if(idx > this->index_used)
        throw "Index entry out of bounds";
    return this->entries[idx].first;
};

template <class T>
T& StandardPermutationIndex<T>::get(const std::size_t idx){
    if(idx > this->index_used)
        throw "Index entry out of bounds";
    return this->entries[idx].first;
};

template <class T>
void StandardPermutationIndex<T>::set_distance_function(int distance_function){
    this->distance_function = distance_function;
}

template <class T>
Permutation StandardPermutationIndex<T>::get_permutation(std::size_t idx){
    if(idx > this->index_used)
        throw "Index entry out of bounds";
    return this->entries[idx].second;
}

template <class T>
void StandardPermutationIndex<T>::build_permutations(){
    if(!this->pivots_generated)
        throw "Cannot build permutations due to the lack of pivots";
    //for each element in the database
    for(size_t i= 0; i < this->index_used; i++){
        //we associate an index with a value
        Permutation target(this->pivot_size);
        for(int i=0; i<this->pivot_size; i++)
            target.permutants[i] = i;
        //we sort the permutation
        std::sort(target.permutants, target.permutants + this->pivot_size, [&](long & a,long & b){
            return entries[a].first.distance_to(entries[i].first, distance_function) < entries[b].first.distance_to(entries[i].first, distance_function);
        });
        this->entries[i].second = target;
    }

}

template <class T>
void StandardPermutationIndex<T>::reset(){
//    for(size_t i=0; i<this->index_used; i++){
//        delete entries[i].second;
//    }
    delete[]this->pivots;
    this->pivot_size = 0;
    this->pivots_generated = false;
}

#endif //METRICHASHING_STANDARDPERMUTATIONINDEX_CPP
