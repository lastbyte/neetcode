#include <iostream>
#include <vector>
int search(std::vector<int> &nums, int target);

int main() {

  std::vector<int> nums = {-1, 0, 2, 4, 6, 8};

  int contain_index_4 = search(nums, 4);
  int contain_index_3 = search(nums, 3);
  std::cout << "Index of 4 in array is : " << contain_index_4 << "\n";
  std::cout << "Index of 3 in array is : " << contain_index_3 << "\n";

  return 0;
}

int search(std::vector<int> &nums, int target) {

  int left = 0, right = nums.size() - 1;

  while (left <= right) {

    int mid = left + (right - left) / 2;

    if (nums.at(mid) == target) {
      return mid;
    }

    if (nums.at(mid) < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}
