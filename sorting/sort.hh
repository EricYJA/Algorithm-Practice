#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

class Sort {
 private:
  int size;
  int upp_lim, low_lim;

  bool reverse;

  bool is_vec;
  int* tgt_arr;
  int* src_arr;

  void swap(int i, int j);

 public:
  Sort() {
    this->size = 1000000;
    this->upp_lim = 10000000;
    this->low_lim = 0;

    this->size = size;
    this->tgt_arr = new int[size];
    this->src_arr = new int[size];

    srand((int)time(0));
    for (int i = 0; i < size; i++) {
      int num = rand() % (upp_lim - low_lim + 1) + low_lim;
      tgt_arr[i] = num;
      src_arr[i] = num;
    }

    sort(tgt_arr, tgt_arr + size);
  }

  Sort(int size): upp_lim(0), low_lim(100) {
    if (size <= 0) {
      printf("Can't generate array with this size, setting size to 1.\n");
      size = 1;
    }

    this->size = size;
    this->tgt_arr = new int[size];
    this->src_arr = new int[size];

    srand((int)time(0));
    for (int i = 0; i < size; i++) {
      int num = rand() % (upp_lim - low_lim + 1) + low_lim;
      tgt_arr[i] = num;
      src_arr[i] = num;
    }
    sort(tgt_arr, tgt_arr + size);
  }

  double bubble_sort(bool reverse = false);
  double selection_sort(bool reverse = false);
  double insertion_sort(bool reverse = false);
  double shell_sort(bool reverse = false);
  double merge_sort(bool reverse = false);

  void reorder_src(int flag) {
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
      if (!reverse && tgt_arr[i] != src_arr[i]) {
        printf("Check FAIL at index: %d\n", i);
        return false;
      } else if (reverse && tgt_arr[i] != src_arr[size - i - 1]) {
        printf("Check FAIL at index: %d\n", i);
        return false;
      }
    }

    printf("Check DONE!\n");
    return true;
  }
  
  void to_string() {
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
};

inline void Sort::swap(int i, int j) {
  int tmp = src_arr[i];
  src_arr[i] = src_arr[j];
  src_arr[j] = tmp;
}

