//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#include "Vectorelement.h"
#include <sstream>
#include <vector>
#include <iterator>

std::size_t VectorElement::dimension;               //dimensions of the space

VectorElement::VectorElement(){
    this->vector = new double[VectorElement::dimension];
    for (size_t i = 0; i<VectorElement::dimension; i++){
        this->vector[i] = 0;
    }
};

VectorElement::~VectorElement(){
//    delete [] this->vector;
};

//Start of setters and getters for static member variables.
void VectorElement::set_dimension(std::size_t dimension){
    VectorElement::dimension = dimension;
}

std::size_t VectorElement::get_dimension(){
    return VectorElement::dimension;
}
//End of setters and getters for static member variables


//Start of static parser functions
VectorElement VectorElement::parse(std::string target){
    std::istringstream iss(target);
    std::vector<std::string> tokens;
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(tokens));
    VectorElement data;
    for (int i=0; i < tokens.size() && i<VectorElement::dimension; i++) {
        data[i] = std::stod(tokens[i]);
    }
    return data;
}
//End of static parser functions


//Start of operator overriding
double& VectorElement::operator[](std::size_t idx){
    if(idx > VectorElement::dimension)
        throw "Array Index Out Of Bounds";
    return this->vector[idx];
}

double& VectorElement::get(std::size_t idx){
    if(idx > VectorElement::dimension)
        throw "Array Index Out Of Bounds";
    return this->vector[idx];
}
//End of operator overriding


//Start of virtual methods implementation
double VectorElement::distance_to(VectorElement target, int distance_function){
    double total_value = 0;
    switch (distance_function) {
        case MANHATTAN_DISTANCE:
            for (size_t i = 0; i<VectorElement::dimension; i++){
                total_value += std::abs(this->vector[i] - target.get(i));
            }
            break;
        case EUCLIEDEAN_DISTANCE:
            for (size_t i = 0; i<VectorElement::dimension; i++){
                total_value += std::pow(this->vector[i] - target.get(i), 2);
            }
            total_value = std::sqrt(total_value);
            break;
        case EUCLIEDEAN_SIMPLE_DISTANCE:
            for (size_t i = 0; i<VectorElement::dimension; i++){
                total_value += std::pow(this->vector[i] - target.get(i), 2);
            }
            break;
        default:
            break;
    }
    return total_value;
}