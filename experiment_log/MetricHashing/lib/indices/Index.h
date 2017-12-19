//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_INDEX_H
#define METRICHASHING_INDEX_H
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <random>
#include <utility>
#include <iostream>
#include "../Permutation/Permutation.h"

template <class T> class Index{
protected:
public:
//    virtual void build() = 0; //TODO implement a generalization of the build routine
    virtual size_t* query_knn(T target, std::size_t k, double working_quota) = 0;
//    virtual size_t* query_range(T &target, double range, double working_quota) = 0; //TODO implement this shit
    virtual int add(T &tgt) = 0;
    virtual T& operator[](const std::size_t idx) = 0;
    virtual T& get(const std::size_t idx) = 0;
    virtual void reset() = 0;
};
#endif //METRICHASHING_INDEX_H
