#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include "sort.hh"


int main() {
  Sort sort = Sort(10000);
  printf("%f\n", sort.insertion_sort());
  sort.check();
  return 0; 
}