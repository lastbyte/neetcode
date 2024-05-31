#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
int trap(std::vector<int> &height);

int main() {

  std::vector<int> heights = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};

  int trappedWater = trap(heights);

  std::cout << "trapped water : " << trappedWater << "\n";

  return 0;
}

int trap(std::vector<int> &height) {

  if (height.size() == 0) {
    return 0;
  }

  int left = 0, right = height.size() - 1;
  int leftMax = height.at(left);
  int rightMax = height.at(right);
  int trappedWater = 0;
  while (left < right) {
    if (leftMax < rightMax) {
      left++;
      leftMax = std::max(leftMax, height.at(left));
      trappedWater += (leftMax - height.at(left));
    } else {
      right--;
      rightMax = std::max(rightMax, height.at(right));
      trappedWater += (rightMax - height.at(right));
    }
  }
  return trappedWater;
}
