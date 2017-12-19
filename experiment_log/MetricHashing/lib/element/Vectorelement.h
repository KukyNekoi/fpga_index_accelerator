//
// Created by Erik Andrés Regla Torres on 3/26/16.
//
#ifndef METRICHASHING_VECTORELEMENT_H
#define METRICHASHING_VECTORELEMENT_H

#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include "Element.h"

//NOTE: EUCLIDEAN_SIMPLE is the same as euclidean, but without the squared root calculation
//applied to it. Since both functions give monotonus ascendant values, there is no loss
//of information to build the permutation index.

////Start of public enums
//enum DistanceFunction{
//    MANHATTAN_DISTANCE,
//    EUCLIEDEAN_DISTANCE,
//    EUCLIEDEAN_SIMPLE_DISTANCE,
//    OTHER_DISTANCE
//};
////End of public enums

//Start of define section
#define    MANHATTAN_DISTANCE           0
#define    EUCLIEDEAN_DISTANCE          1
#define    EUCLIEDEAN_SIMPLE_DISTANCE   2
#define    OTHER_DISTANCE               3
//End of define section

//Start of class VectorElement
class VectorElement : public Element<VectorElement>{
public:
    VectorElement();
    ~VectorElement();
    //Start of setters and getters for static member variables.
    static void set_dimension(std::size_t dimension);
    static std::size_t get_dimension();
    //End of setters and getters for static member variables

    //Start of operator overriding
    double& operator[](std::size_t idx);
    double& get(std::size_t idx);
    //End of operator overriding

    //Start of virtual methods implementation
    double distance_to(VectorElement target, int distance_function);
    //End of virtual methods implementation

    static VectorElement parse(std::string target);
    static std::size_t dimension;               //dimensions of the space

private:
    double *vector;                             //place in where we hold data
};
//End of class VectorElement
#endif //METRICHASHING_VECTORELEMENT_H
