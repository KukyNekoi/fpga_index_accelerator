//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#include "Permutation.h"

//#include "../../tools/Macros.h"

Permutation::Permutation(size_t dimension){
    this->size = dimension;
    this->permutants = (long *) malloc(sizeof(long)*dimension);
    this->inverted = false;
};

/*
 Since all permutants are numbered from 0..p-1 we can invert the index for
 most compared element in order to ease future queries.

 BEWARE THAT THIS DOESNT WORK IF THE RANGE IS NOT 0..p-1
 */
void Permutation::invert_index(){
    long *inverted = (long *) malloc(sizeof(long)*this->size);
    for (size_t i=0; i<this->size; i++) {
        inverted[this->permutants[i]] = i;
    }
    for (size_t i=0; i<this->size; i++) {
        this->permutants[i] = inverted[i];
    }
    this->inverted = !this->inverted;
    delete [] inverted;
};

long Permutation::spearman_rho(Permutation target){
    if(this->inverted == false){
        this->invert_index();
    }
    long distance = 0;
    for (int i=0; i<this->size; i++){
        long temp = (this->permutants[target.permutants[i]] - i);
        distance += temp*temp;
    }
    return distance;
};

long Permutation::spearman_footrule(Permutation target){
    if(this->inverted == false){
        this->invert_index();
    }
    long distance = 0;
    for (int i=0; i<this->size; i++){
        distance += (std::abs(this->permutants[target.permutants[i]] - i));
    }
    return distance;
};

std::string Permutation::to_string(){
    std::stringstream ss;
    ss << "|";
    ss << this->size;
    ss << "|, {";
    for (int i=0; i<this->size; i++) {
        ss << this->permutants[i];
        if(i<this->size-1)
            ss << ", ";
    }
    ss << "}";
    return ss.str();
}
