#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;

class Sort {
 private:
  int size;
  int upp_lim, low_lim;

  bool is_reverse;

  bool is_vec;
  int* tgt_arr;
  int* src_arr;

  void swap(int i, int j);

  void merge_helper(int *A,int n);
  void merge(int *A,int *L,int leftCount,int *R,int rightCount);

 public:
  Sort(int size = 500000, int low_lim = 0, int upp_lim = 1000000); 

  double bubble_sort(bool revs = false);
  double selection_sort(bool revs = false);
  double insertion_sort(bool revs = false);
  double shell_sort(bool revs = false);
  double merge_sort(bool revs = false);

  void reorder_src(int flag = 0) {
    if (flag == 0) {
      srand((int)time(0));
      for (int i = 0; i < size; i++) {
        int num = rand() % (upp_lim - low_lim + 1) + low_lim;
        tgt_arr[i] = num;
        src_arr[i] = num;
      }
      sort(tgt_arr, tgt_arr + size);
    } else if (flag == 1) {
      printf("Sort src to increment\n");
      sort(src_arr, src_arr + size, greater<int>());
    } else if (flag == -1) {
      printf("Sort src to decendent\n");
      sort(src_arr, src_arr + size, less<int>());
    } else {
      printf("Invalid Flag: do nothing.\n");
    }
  }

  bool check() {
    for (int i = 0; i < size; i++) {
      if (!is_reverse && tgt_arr[i] != src_arr[i]) {
        printf("Check FAIL at index: %d\n", i);
        return false;
      } else if (is_reverse && tgt_arr[i] != src_arr[size - i - 1]) {
        printf("Check FAIL at index: %d\n", i);
        return false;
      }
    }

    printf("Check DONE!\n");
    return true;
  }
  
  void print_string() {
    printf("src_arr: ");
    for (int i = 0; i < size; i++) {
      printf("%d ", src_arr[i]);
    }

    printf("\ntgt_arr: ");
    for (int i = 0; i < size; i++) {
      printf("%d ", tgt_arr[i]);
    }
    printf("\n");
  }

  int get_size() {
    return size;
  }
};

inline void Sort::swap(int i, int j) {
  int tmp = src_arr[i];
  src_arr[i] = src_arr[j];
  src_arr[j] = tmp;
}

