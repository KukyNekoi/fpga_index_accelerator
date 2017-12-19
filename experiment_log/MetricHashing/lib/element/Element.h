//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_ELEMENT_H
#define METRICHASHING_ELEMENT_H

template <class T> class Element{
public:
    virtual double distance_to(T target, int distance_function) = 0;
};



#endif //METRICHASHING_ELEMENT_H
