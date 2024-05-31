#include <algorithm>
#include <iostream>
#include <vector>
int maxArea(std::vector<int> &heights);

int main() {

  std::vector<int> heights = {1, 7, 2, 5, 4, 7, 3, 6};

  int mx_area = maxArea(heights);

  std::cout << "Max area : " << mx_area << "\n";

  return 0;
}
int maxArea(std::vector<int> &heights) {

  if (heights.size() == 0) {
    return 0;
  }

  int left = 0, right = heights.size() - 1;

  int max_store = 0;

  while (left < right) {
    int width = right - left;
    if (heights.at(left) < heights.at(right)) {
      int height = std::min(heights.at(left), heights.at(right));
      max_store = std::max(max_store, height * width);
      left++;
    } else {
      int height = std::min(heights.at(left), heights.at(right));
      max_store = std::max(max_store, height * width);
      right--;
    }
  }
  return max_store;
}
