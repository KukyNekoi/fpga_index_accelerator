//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#include "Log.h"
#include "../etc/Macros.h"
#include <sstream>

size_t Log::experiment_id = 0;
std::string Log::path = "";
std::string Log::dataset = "";
size_t Log::distance_calculations = 0;
size_t Log::total_execution_time = 0;
size_t Log::total_full_search_time = 0;
size_t Log::hits = 0;
size_t Log::query_size = 0;
size_t Log::database_size = 0;
size_t Log::pivot_algorithm = 0;
size_t Log::pivots = 0;
size_t Log::permutant_algorithm = 0;
double Log::working_quota = 0;
double Log::alpha_parameter = 0;
size_t Log::dimensions = 0;
std::chrono::high_resolution_clock::time_point Log::execution_time_start, Log::execution_time_end, Log::full_search_time_start, Log::full_search_time_end;



void Log::reset(){
    Log::path = "";
    Log::distance_calculations = 0;
    Log::total_execution_time = 0;
    Log::hits = 0;
    Log::query_size = 0;
    Log::database_size = 0;
    Log::experiment_id++;
    Log::pivot_algorithm = 0;
    Log::permutant_algorithm = 0;
    Log::working_quota = 0;
};

void Log::write_iteration(){
    if(Log::path == "")
        throw "Dump location not set.";

    std::ofstream output_file;
    output_file.open(path, std::ios::out | std::ios::app);

    output_file <<  experiment_id << "\t";
    output_file <<  dataset << "\t";
    output_file <<  database_size << "\t";
    output_file <<  query_size << "\t";
    output_file <<  hits << "\t";
    output_file <<  working_quota << "\t";
    output_file <<  total_execution_time << "\t";
    output_file <<  distance_calculations << "\t";
    output_file <<  pivots << "\t";
    output_file <<  alpha_parameter << "\t";
    output_file <<  ((pivot_algorithm == SSS_ENABLED) ? "SSS" : "RANDOM") << "\t";
    output_file <<  ((permutant_algorithm == PERMUTANTS_ENABLED) ? "PERMUTANT" : "BRUTE_FORCE") << "\n";

    output_file.close();
    Log::experiment_id++;
}

void Log::set_destination(std::string path){
    Log::path = path;
    std::ofstream output_file;
    output_file.open(path, std::ios::out | std::ios::app);

    output_file <<  "experiment_id" << "\t";
    output_file <<  "dataset" << "\t";
    output_file <<  "database_size" << "\t";
    output_file <<  "query_size" << "\t";
    output_file <<  "hits" << "\t";
    output_file <<  "working_quota" << "\t";
    output_file <<  "total_execution_time" << "\t";
    output_file <<  "distance_calculations" << "\t";
    output_file <<  "pivots" << "\t";
    output_file <<  "alpha" << "\t";
    output_file <<  "pivot_algorithm" << "\t";
    output_file <<  "permutant_algorithm"<< "\n";

    output_file.close();

}

void Log::set_dataset(std::string path){
    Log::dataset = path;
}

void Log::increase_distance_counter(){
    Log::distance_calculations++;
}

void Log::start_execution_time(){
    Log::execution_time_start = std::chrono::high_resolution_clock::now();
}

void Log::end_execution_time(){
    Log::execution_time_end = std::chrono::high_resolution_clock::now();
    Log::total_execution_time = std::chrono::duration_cast<std::chrono::microseconds>(execution_time_end - execution_time_start).count();
}

void Log::start_full_search_time(){
    Log::full_search_time_start = std::chrono::high_resolution_clock::now();
}

void Log::end_full_search_time(){
    Log::full_search_time_end = std::chrono::high_resolution_clock::now();
    Log::total_full_search_time = std::chrono::duration_cast<std::chrono::microseconds>(full_search_time_end - full_search_time_start).count();
}

void Log::set_query_size(size_t value){
    Log::query_size = value;
}

void Log::set_query_hits(size_t value){
    Log::hits = value;
}

void Log::set_database_size(size_t value){
    Log::database_size = value;
}

void Log::set_working_quota(double value){
    Log::working_quota = value;
}


void Log::set_alpha(double value){
    Log::alpha_parameter = value;
}


//void Log::append_sstream_to_file(std::stringstream input, std::string path){
//    Log::path = path;
//    std::ofstream output_file;
//    output_file.open(path, std::ios::out | std::ios::app);
//    output_file <<  input << "\n";
//    output_file.close();
//
//}
