//
// Created by Erik Andrés Regla Torres on 3/29/16.
//

#include "Experiment.h"
#include "../etc/Macros.h"

Experiment::Experiment(){
};

Experiment::~Experiment(){
};

void Experiment::set_output_path(std::string path){
    this->output_path = path;
};

void Experiment::add_dataset(std::string path){
    this->datasets.push_back(path);
}

void Experiment::add_queries(std::string path){
    this->queries.push_back(path);
}

void Experiment::run_series(bool dump){
    //load all datasets onto ram
    //set destination file
    Log::set_destination(this->output_path);
    for (size_t i=0; i< this->datasets.size(); i++) {
        Log::set_dataset(this->datasets[i]);
        std::string line;
        std::ifstream myfile(this->datasets[i].c_str());
        StandardPermutationIndex<VectorElement> *index = NULL;
        //load data for index
        if (myfile.is_open()){
            getline (myfile,line);
            std::istringstream iss(line);
            std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                            std::istream_iterator<std::string>{}};

            int values = std::stoi(tokens[1]);
            index = new StandardPermutationIndex<VectorElement>(values);
            VectorElement::set_dimension(std::stoi(tokens[0]));

            while ( getline (myfile,line) ){
                VectorElement temp = VectorElement::parse(line);
                index->add(temp);
            }
            myfile.close();
        }

        //load queries
        std::vector<VectorElement> q;
        for(size_t j=0; j < this->queries.size(); j++){
            myfile.open(this->queries[j].c_str());
            if (myfile.is_open()){
                while ( getline (myfile,line) ){
                    VectorElement temp = VectorElement::parse(line);
                    q.push_back(temp);
                }
                myfile.close();
            }

        }

        //set log variables

        Log::set_database_size(index->index_used);
        //instanciate index
        index->set_distance_function(EUCLIEDEAN_DISTANCE);

        for(size_t sss_exponent = 1; sss_exponent <= 8; sss_exponent++ ){
            //we always use 1% of the dataset for SS sampling
            //            Log::set_alpha(alpha);
            if(index->pivots_generated){ index->reset(); }

            size_t sss_size = std::pow(2, sss_exponent);
            index->get_forced_sss_pivots(0.01, sss_size);
            index->build_permutations();        //run queries
            size_t query_size = 0;
            for(size_t exponent = 5; exponent <= 8; exponent++ )
            {
                query_size = std::pow(2, exponent);
                for(double working_quota = 1; working_quota <= 1 ; working_quota += 0.01){
                    Log::set_working_quota(working_quota);
                    Log::set_query_size(query_size);
                    for(size_t j=0; j < q.size(); j++){
                        Log::start_execution_time();
                        size_t *query_results = index->query_knn(q[j], query_size, working_quota);
                        Permutation query_permutation = index->get_permutation(q[j]);
                        Log::end_execution_time();
                        Log::pivots = index->pivot_size;
                        Log::pivot_algorithm = SSS_ENABLED;
                        Log::permutant_algorithm = PERMUTANTS_ENABLED;
                        size_t hybrid_answer_size = 0;
                        size_t *hybrid_answer = index->bf_query_hybrid_knn(q[j], query_size, hybrid_answer_size);
                        std::sort(query_results,
                                  query_results+query_size);
                        std::sort(hybrid_answer,
                                  hybrid_answer+hybrid_answer_size);
                        std::cout << "EXPERIMENT:\t" << Log::experiment_id << ":\n";
                        std::cout << "QUERY:\t" << index->get_permutation(q[j]).to_string() << ":\n";
                        size_t i_ptr = 0, j_ptr = 0, count = 0;
                        while(i_ptr < query_size && j_ptr < hybrid_answer_size){
                            if(query_results[i_ptr] == hybrid_answer[j_ptr]){
                                i_ptr++;
                                j_ptr++;
                                count++;
                            }
                            else if(query_results[i_ptr] < hybrid_answer[j_ptr])
                                i_ptr++;
                            else if(query_results[i_ptr] > hybrid_answer[j_ptr])
                                j_ptr++;
                        }
                        std::sort(query_results, query_results+query_size, [&](size_t & a,size_t & b){
                            return q[j].distance_to(index->get(a), EUCLIEDEAN_DISTANCE) < q[j].distance_to(index->get(b), EUCLIEDEAN_DISTANCE);
                        });
                        for(size_t i = 0; i<query_size; i++){
                            std::cout << "RESULT [" << q[j].distance_to(index->get(query_results[i]), EUCLIEDEAN_DISTANCE) << "] \t[" << query_permutation.spearman_footrule(index->get_permutation(query_results[i])) << "]:\t" << index->get_permutation(query_results[i]).to_string() << ":\n";
                        }
                        Log::set_query_hits(count);
                        Log::write_iteration();
                    }
                }
            }
        }
    }
}

void Experiment::run_bf_series(bool dump){
    //load all datasets onto ram
    //set destination file
    Log::set_destination(this->output_path);
    for (size_t i=0; i< this->datasets.size(); i++) {
        Log::set_dataset(this->datasets[i]);
        std::string line;
        std::ifstream myfile(this->datasets[i].c_str());
        StandardPermutationIndex<VectorElement> *index = NULL;
        //load data for index
        if (myfile.is_open()){
            getline (myfile,line);
            std::istringstream iss(line);
            std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                            std::istream_iterator<std::string>{}};

            int values = std::stoi(tokens[1]);
            index = new StandardPermutationIndex<VectorElement>(values);
            VectorElement::set_dimension(std::stoi(tokens[0]));

            while ( getline (myfile,line) ){
                VectorElement temp = VectorElement::parse(line);
                index->add(temp);
            }
            myfile.close();
        }

        //load queries
        std::vector<VectorElement> q;
        for(size_t j=0; j < this->queries.size(); j++){
            myfile.open(this->queries[j].c_str());
            if (myfile.is_open()){
                while ( getline (myfile,line) ){
                    VectorElement temp = VectorElement::parse(line);
                    q.push_back(temp);
                }
                myfile.close();
            }

        }

        //set log variables

        Log::set_database_size(index->index_used);
        //instanciate index
        index->set_distance_function(EUCLIEDEAN_DISTANCE);

        for(size_t sss_exponent = 1; sss_exponent <= 8; sss_exponent++ ){
            //we always use 1% of the dataset for SS sampling
            //            Log::set_alpha(alpha);
            if(index->pivots_generated){ index->reset(); }

            size_t sss_size = std::pow(2, sss_exponent);
            index->get_forced_sss_pivots(0.01, sss_size);
            index->build_permutations();        //run queries
            size_t query_size = 0;
            for(size_t exponent = 5; exponent <= 8; exponent++ )
            {
                query_size = std::pow(2, exponent);
                for(double working_quota = 1; working_quota <= 1 ; working_quota += 0.01){
                    Log::set_working_quota(working_quota);
                    Log::set_query_size(query_size);
                    for(size_t j=0; j < q.size(); j++){
                        Log::start_execution_time();
                        size_t *query_results = index->bf_query_knn(q[j], query_size);
                        Permutation query_permutation = index->get_permutation(q[j]);
                        Log::end_execution_time();
                        Log::pivots = index->pivot_size;
                        Log::pivot_algorithm = SSS_ENABLED;
                        Log::permutant_algorithm = PERMUTANTS_ENABLED;
                        std::cout << "EXPERIMENT:\t" << Log::experiment_id << ":\n";
                        std::cout << "QUERY:\t" << index->get_permutation(q[j]).to_string() << ":\n";
                        std::sort(query_results, query_results+query_size, [&](size_t & a,size_t & b){
                            return q[j].distance_to(index->get(a), EUCLIEDEAN_DISTANCE) < q[j].distance_to(index->get(b), EUCLIEDEAN_DISTANCE);
                        });
                        for(size_t i = 0; i<query_size; i++){
                            std::cout << "RESULT [" << q[j].distance_to(index->get(query_results[i]), EUCLIEDEAN_DISTANCE) << "] \t[" << query_permutation.spearman_footrule(index->get_permutation(query_results[i])) << "]:\t" << index->get_permutation(query_results[i]).to_string() << ":\n";
                        }
                        Log::set_query_hits(query_size);
                        Log::write_iteration();
                    }
                }
            }
        }
    }
}

void Experiment::run_bf_series_two(bool dump){
    //load all datasets onto ram
    //set destination file
    Log::set_destination(this->output_path);
    for (size_t i=0; i< this->datasets.size(); i++) {
        Log::set_dataset(this->datasets[i]);
        std::string line;
        std::ifstream myfile(this->datasets[i].c_str());
        StandardPermutationIndex<VectorElement> *index = NULL;
        //load data for index
        if (myfile.is_open()){
            getline (myfile,line);
            std::istringstream iss(line);
            std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                            std::istream_iterator<std::string>{}};

            int values = std::stoi(tokens[1]);
            index = new StandardPermutationIndex<VectorElement>(values);
            VectorElement::set_dimension(std::stoi(tokens[0]));

            while ( getline (myfile,line) ){
                VectorElement temp = VectorElement::parse(line);
                index->add(temp);
            }
            myfile.close();
        }

        //load queries
        std::vector<VectorElement> q;
        for(size_t j=0; j < this->queries.size(); j++){
            myfile.open(this->queries[j].c_str());
            if (myfile.is_open()){
                while ( getline (myfile,line) ){
                    VectorElement temp = VectorElement::parse(line);
                    q.push_back(temp);
                }
                myfile.close();
            }

        }

        //set log variables

        Log::set_database_size(index->index_used);
        //instanciate index
        index->set_distance_function(EUCLIEDEAN_DISTANCE);

        for(size_t sss_exponent = 1; sss_exponent <= 8; sss_exponent++ ){
            //we always use 1% of the dataset for SS sampling
            //            Log::set_alpha(alpha);
            if(index->pivots_generated){ index->reset(); }

            size_t sss_size = std::pow(2, sss_exponent);
            index->get_forced_sss_pivots(0.01, sss_size);
            index->build_permutations();        //run queries
            size_t query_size = 0;
            query_size = 1024;
            for(double working_quota = 1; working_quota <= 1 ; working_quota += 0.01){
                Log::set_working_quota(working_quota);
                Log::set_query_size(query_size);
                for(size_t j=0; j < q.size(); j++){
                    Log::start_execution_time();
                    size_t *query_results = index->query_naive_knn(q[j], query_size);
                    Permutation query_permutation = index->get_permutation(q[j]);
                    Log::end_execution_time();
                    Log::pivots = index->pivot_size;
                    Log::pivot_algorithm = SSS_ENABLED;
                    Log::permutant_algorithm = PERMUTANTS_ENABLED;
                    std::cout << "EXPERIMENT:\t" << Log::experiment_id << ":\n";
                    std::cout << "QUERY:\t" << index->get_permutation(q[j]).to_string() << ":\n";
                    for(size_t i = 0; i<query_size; i++){
                        std::cout << "RESULT [" << q[j].distance_to(index->get(query_results[i]), EUCLIEDEAN_DISTANCE) << "] \t[" << query_permutation.spearman_footrule(index->get_permutation(query_results[i])) << "]:\t" << index->get_permutation(query_results[i]).to_string() << ":\n";
                    }
                    Log::set_query_hits(query_size);
                    Log::write_iteration();
                }
            }

        }
    }
}
