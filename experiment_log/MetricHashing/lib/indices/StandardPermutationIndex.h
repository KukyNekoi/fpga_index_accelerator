//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_STANDARDPERMUTATIONINDEX_H
#define METRICHASHING_STANDARDPERMUTATIONINDEX_H


#include <algorithm>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <random>
#include <utility>
#include <iostream>
#include "../Permutation/Permutation.h"
#include "../log/Log.h"
#include "Index.h"

template <class T> class StandardPermutationIndex : public Index<T>{
public:
    StandardPermutationIndex<T>(std::size_t size = 1);
    void get_random_pivots(double factor);
    void get_sss_pivots(double factor = 0.0, double alpha = 0.34);
    void get_forced_sss_pivots(double factor = 0.0, size_t pivot_amount = 32);
    void build_permutations();
    Permutation get_permutation(std::size_t idx);
    size_t* query_knn(T target, std::size_t k, double working_quota = 0.02);
    size_t* query_naive_knn(T target, std::size_t k);
    //size_t* query_by_range(T &target, double range, double working_quota = 0.02);
    size_t* bf_query_knn(T target, std::size_t k);      //bruteforce methods
    size_t* bf_query_by_range(T &target, double range, size_t &size); //bruteforce method two
    size_t* bf_query_hybrid_knn(T &target, std::size_t k, size_t &size); //bruteforce method three
    int add(T &tgt);
    T& operator[](const std::size_t idx);
    T& get(const std::size_t idx);
    void set_distance_function(int distance_function);
    void reset();
//private:
    size_t *pivots;
    size_t pivot_size = 0;
    size_t index_size = 0;
    size_t index_used = 0;
    int distance_function = 0;
    std::pair<T, Permutation> *entries;     //TODO correct this thing. it should be two
    Permutation get_permutation(T &target); //separate structures in order to not affect
    bool pivots_generated;                  //the underlying implementation
};

#include "StandardPermutationIndex.cpp"

#endif //METRICHASHING_STANDARDPERMUTATIONINDEX_H
