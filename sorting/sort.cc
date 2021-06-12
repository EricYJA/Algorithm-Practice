#include "sort.hh"
Sort::Sort(int _size, int _low_lim, int _upp_lim): 
            size(_size), low_lim(_low_lim), upp_lim(_upp_lim) {
  if (size <= 0) {
    printf("Can't generate array with this size, setting size to 1.\n");
    size = 1;
  }

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


double Sort::bubble_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  if (!is_reverse) {
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

double Sort::selection_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  if (!is_reverse) {
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

double Sort::insertion_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  if (!is_reverse) {
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

double Sort::shell_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  if (!is_reverse) {
    int gap, i, j;
    int temp;
    while (gap < size / 5) {
      gap = gap * 3 + 1; 
    }
    for (; gap > 0; gap /= 3) {
      for (i = gap; i < size; i++) {
        temp = src_arr[i];
        for (j = i - gap; j >= 0 && src_arr[j] > temp; j -= gap)
          src_arr[j + gap] = src_arr[j];
        src_arr[j + gap] = temp;
      }
    }
  } else {
    int gap, i, j;
    int temp;
    while (gap < size / 5) {
      gap = gap * 3 + 1;
    }
    for (; gap > 0; gap /= 3) {
      for (i = gap; i < size; i++) {
        temp = src_arr[i];
        for (j = i - gap; j >= 0 && src_arr[j] < temp; j -= gap)
          src_arr[j + gap] = src_arr[j];
        src_arr[j + gap] = temp;
      }
    }
  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::merge_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

void Sort::merge_helper(int *A, int n) {
  int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing.
 
	mid = n/2;  // find the mid index.
 
	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = new int[mid];
	R = new int [n - mid];
 
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
 
	merge_helper(L,mid);  // sorting the left subarray
	merge_helper(R,n-mid);  // sorting the right subarray
	merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	// the delete operations is very important
	delete [] R;
	delete [] L;
}

void Sort::merge(int *A,int *L,int leftCount,int *R,int rightCount) {
  int i,j,k;
 
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i < leftCount && j < rightCount) {
    if (!is_reverse) {
      if(L[i] < R[j]) A[k++] = L[i++];
		  else A[k++] = R[j++];
    } else {
      if(L[i] > R[j]) A[k++] = L[i++];
		  else A[k++] = R[j++];
    }
	}

	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

double Sort::quick_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::heap_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::counting_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::bucket_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}

double Sort::radix_sort(bool revs) {
  auto start = std::chrono::system_clock::now();

  this->is_reverse = revs;
  merge_helper(src_arr, size);

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return double(duration.count()) 
            * std::chrono::microseconds::period::num 
            / std::chrono::microseconds::period::den;
}