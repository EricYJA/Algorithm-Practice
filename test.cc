#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int quick_helper(vector<int>& nums, int srt, int end, int idx) {
        if (srt < end) {
            int index = partition(nums, srt, end);
            printf("%d\n", index);
            if (index < idx) {
                return quick_helper(nums, index + 1, end, idx);
            } else if (index > idx) {
                return quick_helper(nums, srt, index, idx);
            } else {
                return nums[index];
            }
        }
        return nums[srt];
    }

    int partition(vector<int>& nums, int srt, int end) {
        int pivot = srt;
        for (int i = srt + 1; i <= end; i++) {
            if (nums[i] > nums[srt]) {
                ++pivot;
                swap(nums, i, pivot);
            }
        }
        swap(nums, pivot, srt);
        return pivot;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        return quick_helper(nums, 0, size -1, k - 1);
    }
};


int main() {
  Solution sol;
  int arr[] = {3,5,5,6,1,2,3,2,4};
  vector<int> a(arr, arr + 9);
  printf("%d\n", sol.findKthLargest(a, 4));
  return 0;
}