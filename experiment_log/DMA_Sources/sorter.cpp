// sort algorithm example
#include <stdint.h>
#include <sys/time.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

struct timespec start, end;


int main () {
  std::vector<int> myvector;               // 32 71 12 45 26 80 53 33
  for(int i=0; i<10000; i++){
      myvector.push_back(rand()%10000);
  }

  // using default comparison (operator <):
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  std::sort (myvector.begin(), myvector.end());
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  
  uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

  // print out content:
  std::cout << "elapsed_time: " << delta_us << std::endl;

  return 0;
}