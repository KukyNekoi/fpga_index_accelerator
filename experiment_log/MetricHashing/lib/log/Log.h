//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_LOG_H
#define METRICHASHING_LOG_H

#include <stdio.h>
#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>

class Log{
public:
    static void reset();
    static void write_iteration();
    static void set_destination(std::string path); //done
    static void set_dataset(std::string path); //done
    static void increase_distance_counter();
    static void start_execution_time(); //done
    static void end_execution_time(); //done
    static void start_full_search_time();
    static void end_full_search_time();
    static void set_query_size(size_t value); //done
    static void set_query_hits(size_t value); //done
    static void set_database_size(size_t value); //done
    static void set_experiment_id(size_t value);
    static void set_working_quota(double value); //done
    static void set_alpha(double value); //done
//    static void append_sstream_to_file(std::stringstream input, std::string output);

    static bool initializated;
    static std::string path;
    static std::string dataset;
    static size_t distance_calculations;
    static size_t total_execution_time;
    static size_t total_full_search_time;
    static size_t hits;
    static size_t query_size;
    static size_t database_size;
    static size_t experiment_id;
    static size_t pivot_algorithm;
    static size_t permutant_algorithm;
    static double working_quota;
    static size_t dimensions;
    static double alpha_parameter;
    static size_t pivots;
    static std::chrono::high_resolution_clock::time_point execution_time_start, execution_time_end, full_search_time_start, full_search_time_end;
};
#endif //METRICHASHING_LOG_H
