#include "sort.hh"

double Sort::bubble_sort(bool reverse) {
  auto start = std::chrono::system_clock::now();

  this->reverse = reverse;
  if (!reverse) {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - 1 - i; j++) {
        if (src_arr[j] > src_arr[j + 1]) {
          swap(j, j + 1);
        }
      }
    }
  } else {
    for (int i = 0; i < size; i++) {
      for (int j = size - 1; j > i; j--) {
        if (src_arr[j - 1] < src_arr[j]) {
          swap(j - 1, j);
        }
      }
    }
  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::selection_sort(bool reverse) {
  auto start = std::chrono::system_clock::now();

  this->reverse = reverse;
  if (!reverse) {
    int tmp;
    for (int i = 0; i < size; i++) {
      tmp = i;
      for (int j = i; j < size; j++) {
        if (src_arr[tmp] > src_arr[j]) {
          tmp = j;
        }
      }
      swap(tmp, i);
    }
  } else {
    int tmp;
    for (int i = size - 1; i >= 0; i--) {
      tmp = i;
      for (int j = i; j >= 0; j--) {
        if (src_arr[tmp] > src_arr[j]) {
          tmp = j;
        }
      }
      swap(tmp, i);
    }
  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::insertion_sort(bool reverse) {
  auto start = std::chrono::system_clock::now();

  this->reverse = reverse;
  if (!reverse) {
    for (int i = 0; i < size; i++) {
      for (int j = i; j > 0; j--) {
        if (src_arr[j] < src_arr[j - 1]) {
          swap(j, j-1);
        } else {
          break;
        }
      }
    }
  } else {
    for (int i = size - 1; i >= 0; i--) {
      for (int j = i; j < size; j++) {
        if (src_arr[j] > src_arr[j - 1]) {
          swap(j, j-1);
        } else {
          break;
        }
      }
    }
  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::shell_sort(bool reverse) {
  auto start = std::chrono::system_clock::now();

  this->reverse = reverse;
  if (reverse) {
    
  } else {

  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::merge_sort(bool reverse) {
  auto start = std::chrono::system_clock::now();

  this->reverse = reverse;
  if (reverse) {
    
  } else {

  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}