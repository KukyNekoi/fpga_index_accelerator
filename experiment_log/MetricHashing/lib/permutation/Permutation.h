//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_PERMUTATION_H
#define METRICHASHING_PERMUTATION_H


#include <string>
#include <sstream>

class Permutation{
private:
    void invert_index();
protected:
public:
    long *permutants;
    std::size_t size;
    bool inverted;
    Permutation(size_t dimension = 0);
    long spearman_rho(Permutation target);
    long spearman_footrule(Permutation target);
    std::string to_string();
};


#endif //METRICHASHING_PERMUTATION_H
