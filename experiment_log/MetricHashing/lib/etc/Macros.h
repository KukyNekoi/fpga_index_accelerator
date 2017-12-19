//
// Created by Erik Andrés Regla Torres on 3/26/16.
//

#ifndef METRICHASHING_MACROS_H
#define METRICHASHING_MACROS_H
#include "Flags.h"

#define SSS_ENABLED 0
#define PERMUTANTS_ENABLED 0

#define VARDUMP(X) std::cout << #X << " = " << X << std::endl
#define NEWLINE() std::cout << std::endl
#define PRINT(X) std::cout << X
#define PRINTLN(X) std::cout << X << std::endl

#define SECTION(X, Y) std::cout << "********  START OF SECTION " << X << " ********" << std::endl; Y ; std::cout << "******** END OF SECTION " << X << " ********" << std::endl << std::endl;

#ifdef VERBOSE
#define DEBUG(X) X
#else
#define DEBUG(X)
#endif

#ifdef VIEWPORT_DEBUG
#define V_DEBUG(X) X
#else
#define V_DEBUG(X)
#endif

#ifdef VISUALIZE
#define VIEWPORT_CALLBACK(X) X
#else
#define VIEWPORT_CALLBACK(X)
#endif

#endif //METRICHASHING_MACROS_H
