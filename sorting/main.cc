#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include "sort.hh"


int main() {
  Sort sort = Sort(10, 0, 20);
  // printf("bubble sort time: %f Size: %d \n", sort.bubble_sort(), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  // printf("selection sort time: %f Size: %d \n", sort.selection_sort(), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  // printf("insertion sort time: %f Size: %d \n", sort.insertion_sort(), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  // printf("shell sort time: %f Size: %d \n", sort.shell_sort(), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  // printf("merge sort time: %f Size: %d \n", sort.merge_sort(), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  // printf("quick sort time: %f Size: %d \n", sort.quick_sort(true), sort.get_size());
  // sort.check();
  // sort.reorder_src();
  printf("heap sort time: %f Size: %d \n", sort.heap_sort(true), sort.get_size());
  sort.print_string();
  sort.check();

  return 0;
}