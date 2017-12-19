//
// Created by Erik Andrés Regla Torres on 3/29/16.
//

#ifndef METRICHASHING_EXPERIMENT_H
#define METRICHASHING_EXPERIMENT_H


#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include "../element/Vectorelement.h"
#include "../log/Log.h"
#include "../indices/StandardPermutationIndex.h"
class Experiment{
public:
    Experiment();
    ~Experiment();

    void set_output_path(std::string path);
    void add_dataset(std::string path);
    void add_queries(std::string path);
    void run_experiment(size_t id, bool dump = true, bool visualize = false);
    void run_series(bool dump = true);
    void run_bf_series(bool dump = true); //for permutant testing on real distances
    void run_bf_series_two(bool dump = true); //for permutant testing on permutation distances

private:
    std::vector<std::string> datasets;
    std::vector<std::string> queries;
    std::string output_path;
};


#endif //METRICHASHING_EXPERIMENT_H
