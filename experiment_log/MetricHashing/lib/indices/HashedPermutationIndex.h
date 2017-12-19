//
// Created by Erik Andrés Regla Torres on 3/29/16.
//

#ifndef METRICHASHING_HASHEDPERMUTATIONINDEX_H
#define METRICHASHING_HASHEDPERMUTATIONINDEX_H

#include "Index.h"
#include "../log/Log.h"
//TODO make this shit work by implementing hashed index for SSS permutation-based index
template <class T> class HashedPermutationIndex : public Index<T>{
public:
    //build members
    void get_random_pivots(double factor);
    void get_sss_pivots(double factor = 0.0, double alpha = 0.34);
    void get_forced_sss_pivots(double factor = 0.0, size_t pivot_amount = 32);


    //    virtual void build() = 0;
    size_t* query_knn(T target, std::size_t k, double working_quota);
    //    virtual size_t* query_range(T &target, double range, double working_quota) = 0;
    int add(T &tgt);
    HashedPermutationIndex<T>(std::size_t size = 1);
    T& operator[](const std::size_t idx);
    T& get(const std::size_t idx);
    void reset();

    //private statement

    //inherited members
    T *objects;                 //index objects
    size_t index_size = 0;
    size_t index_used = 0;
    int distance_function = 0;

    //propietary members
    size_t *pivots;
    size_t pivot_size = 0;
    Permutation *main_permutations;
    Permutation *aux_permutations;
    Permutation get_permutation(T &target); //separate structures in order to not affect


    //std::pair<T, Permutation> *entries;     //TODO correct this thing. it should be two
    bool pivots_generated;                  //the underlying implementation
};


#endif //METRICHASHING_HASHEDPERMUTATIONINDEX_H
