//
// Created by Erik Andrés Regla Torres on 3/29/16.
//
#ifndef METRICHASHING_HASHEDPERMUTATIONINDEX_CPP
#define METRICHASHING_HASHEDPERMUTATIONINDEX_CPP

#include "HashedPermutationIndex.h"

template <class T>
void HashedPermutationIndex<T>::get_random_pivots(double factor){
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
void HashedPermutationIndex<T>::get_forced_sss_pivots(double factor, size_t pivot_amount){
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
void HashedPermutationIndex<T>::get_sss_pivots(double factor, double alpha){
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
            double dist = objects[sample[i]].distance_to(objects[sample[j]], this->distance_function);
            if(dist > max_distance)
                max_distance = dist;
        }
    }

    //free memory
    delete [] sample;

    //Insert the first element as pivot
    std::vector<size_t> t_pivots;
    t_pivots.push_back(0);
    // for each new element if distance to all pivots exceeds (max*alpha) add as pivots
    for(int i = 1; i < current_index_size; i++){
        bool accepted = true;
        for(int j = 0; j < t_pivots.size(); j++){
            double dist = objects[i].distance_to(objects[t_pivots[j]], this->distance_function);
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
int HashedPermutationIndex<T>::add(T &tgt){
    if(this->index_used >=   this->index_size){
        throw "Index space fully used, cannot add new objects to it. :c";
    }
    this->objects[this->index_used] = tgt;
    this->main_permutations[this->index_used] = Permutation();
    this->index_used++;
    return 0;
}

template <class T>
T& HashedPermutationIndex<T>::operator[](const std::size_t idx){
    if(idx > this->index_used)
        throw "Index entry out of bounds";
    return this->objects[idx];
};

template <class T>
T& HashedPermutationIndex<T>::get(const std::size_t idx){
    if(idx > this->index_used)
        throw "Index entry out of bounds";
    return this->objects[idx];
};

//template <class T>
//void HashedPermutationIndex<T>::set_distance_function(int distance_function){
//    this->distance_function = distance_function;
//}
//
//template <class T>
//Permutation HashedPermutationIndex<T>::get_main_permutation(std::size_t idx){
//    if(idx > this->index_used)
//        throw "Index entry out of bounds";
//    return this->main_permutations[idx];
//}
//template <class T>
//Permutation HashedPermutationIndex<T>::get_main_permutation(std::size_t idx){
//    if(idx > this->index_used)
//        throw "Index entry out of bounds";
//    return this->main_permutations[idx];
//}
//
//template <class T>
//Permutation HashedPermutationIndex<T>::get_aux_permutation(std::size_t idx){
//    if(idx > this->index_used)
//        throw "Index entry out of bounds";
//    return this->aux_permutations[idx];
//}
//template <class T>
//Permutation HashedPermutationIndex<T>::get_aux_permutation(std::size_t idx){
//    if(idx > this->index_used)
//        throw "Index entry out of bounds";
//    return this->aux_permutations[idx];
//}

#endif //METRICHASHING_HASHEDPERMUTATIONINDEX_CPP