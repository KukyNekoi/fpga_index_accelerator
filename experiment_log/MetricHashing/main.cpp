#include <iostream>
#include <stdio.h>
#include "lib/etc/Macros.h"
#include "lib/visualization/Screen.h"
#include "lib/element/VectorElement.h"
#include "lib/permutation/Permutation.h"
#include "lib/indices/StandardPermutationIndex.h"
#include "lib/canned_food/Experiment.h"

int do_experiment();
int demo();

int main() {
    std::cout << "METRIC HASHING it's just another crazy idea from DCC's Of. 19. There is two\n"
                         "ways to execute this thing. the first one is to invoke the demo() function\n"
                         "to run a graphical demo of a query. It's kinda old, so I wouldn't rely on it.\n"
                         "The other method is to call an <Experiment> instance, which you can see in the\n"
                         "another method called do_experiment. Just invoke it from this main routine\n"
                         "and watch.\n\n"
                         "Good luck!"
                         "" << std::endl;

                         //do_experiment();
                         demo();
    return 0;
}

int do_experiment(){
    Experiment run;
    run.add_dataset("../dbs/uniform_2D_10000.ascii");
    run.add_dataset("../dbs/uniform_4D_10000.ascii");
    run.add_dataset("../dbs/uniform_8D_10000.ascii");
//    run.add_dataset("/Users/jvarred/Documents/Sources/2015/Research/Permutants/Permutants/dbs/uniform_16D_100000.ascii");
//    run.add_dataset("/Users/jvarred/Documents/Sources/2015/Research/Permutants/Permutants/dbs/uniform_32D_100000.ascii");
//    run.add_dataset("/Users/jvarred/Documents/Sources/2015/Research/Permutants/Permutants/dbs/uniform_64D_100000.ascii");
//    run.add_dataset("/Users/jvarred/Documents/Sources/2015/Research/Permutants/Permutants/dbs/uniform_128D_1000000.ascii");
    run.add_dataset("../dbs/uniform_32D_10000.ascii");
    run.add_dataset("..dbs/uniform_64D_10000.ascii");
    run.add_dataset("../dbs/uniform_128D_10000.ascii");
    run.add_queries("../queries/q1.txt");
    run.set_output_path("../output/log.txt");
//    run.run_bf_series();
    run.run_bf_series_two();

    return 0 ;
}

int demo() {
    SECTION("PERMUTANT TEST", {
        Permutation q1(7);
        Permutation p1(7);
        p1.permutants[0] = 3;
        p1.permutants[1] = 6;
        p1.permutants[2] = 1;
        p1.permutants[3] = 2;
        p1.permutants[4] = 4;
        p1.permutants[5] = 0;
        p1.permutants[6] = 5;

        q1.permutants[0] = 5;
        q1.permutants[1] = 1;
        q1.permutants[2] = 4;
        q1.permutants[3] = 3;
        q1.permutants[4] = 2;
        q1.permutants[5] = 6;
        q1.permutants[6] = 0;


        VARDUMP(p1.to_string());
        VARDUMP(q1.to_string());
        VARDUMP(q1.spearman_footrule(p1));
        VARDUMP(q1.to_string());
    })
//
    StandardPermutationIndex<VectorElement> index(10000);
    VectorElement::set_dimension(2);
    std::ifstream myfile ("../dbs/uniform_2D_10000.ascii");
    std::string line;
    if (myfile.is_open()){
        getline (myfile,line);
        while ( getline (myfile,line) ){
            VectorElement temp = VectorElement::parse(line);
            index.add(temp);
        }
        myfile.close();
    }

    VIEWPORT_CALLBACK(
            Screen viewport(700,700);
    viewport.clear();
    )

#define SSS_GENERATION

    index.set_distance_function(EUCLIEDEAN_DISTANCE);
    //TODO: Separate experiments for absolute, random and SSS
    SECTION("PIVOT SELECTION",
#ifndef SSS_GENERATION
    index.get_random_pivots(0.02);
            SECTION("SELECTED RANDOM PIVOTS",
                    std::cout << "INDEX_PIVOTS SIZE=" << index.pivot_size << std::endl;
                    for(int i=0; i<index.pivot_size; i++){
                        std::cout << " " << index.pivots[i];
                        VIEWPORT_CALLBACK(viewport.draw_dot(index.get(index.pivots[i]).get(0), index.get(index.pivots[i]).get(1), 6, 0xFF));
                    }
                    NEWLINE();
            )
#else
            index.get_sss_pivots(0.02);
    SECTION("SELECTED SSS PIVOTS",
            std::cout << "INDEX_PIVOTS SIZE=" << index.pivot_size << std::endl;
    for(int i=0; i<index.pivot_size; i++){
        std::cout << " " << index.pivots[i];
        VIEWPORT_CALLBACK(viewport.draw_dot(index.get(index.pivots[i]).get(0), index.get(index.pivots[i]).get(1), 8, 0x40, 0x40, 0x40));
    }
    NEWLINE();
    )
#endif
    )


    SECTION("PERMUTATION BUILD",
            index.build_permutations();
    )

    SECTION("INDEX PERMUTATIONS",
    for(int i=0; i<index.index_size; i++){
        std::cout << "IDX=" << i << "\t PERM=" << index.get_permutation(i).to_string() << "\n";
        VIEWPORT_CALLBACK(viewport.draw_dot(index.get(i).get(0), index.get(i).get(1), 2));
    }
    )


    VectorElement query = VectorElement::parse("0.5 0.5");

    SECTION("QUERY RESULTS",
            //brute force results
            VIEWPORT_CALLBACK(viewport.draw_dot(0.5, 0.5 , 8, 0x00, 0xC2, 0xC2));
    size_t query_size = 0;
    size_t *bf_result = index.bf_query_hybrid_knn(query, 40, query_size);
    for (int i=0; i<query_size; i++) {
        std::cout << "BF_RESULT[" << i << "]=" << index.get(bf_result[i]).get(0) << " " <<index.get(bf_result[i]).get(1) << std::endl;
        VIEWPORT_CALLBACK(viewport.draw_dot(index.get(bf_result[i]).get(0), index.get(bf_result[i]).get(1), 8, 0xC2, 0xC2, 0xC2));
    }

    //heuristic result
    size_t *result = index.query_knn(query, 40, 0.1);
    for (int i=0; i<40; i++) {
        std::cout << "RESULT[" << i << "]=" << index.get(result[i]).get(0) << " " <<index.get(result[i]).get(1) << std::endl;
        VIEWPORT_CALLBACK(viewport.draw_dot(index.get(result[i]).get(0), index.get(result[i]).get(1), 4, 0x00, 0xFF));
    }
    )

    VIEWPORT_CALLBACK(
            viewport.update();
    PRINTLN("PRESS [ENTER] TO EXIT GRAPHICAL MODE");
    getchar();
    )

    return 0;
}
