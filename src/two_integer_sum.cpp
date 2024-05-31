#include <iostream>
#include <map>
#include <vector>
std::vector<int> twoSum(std::vector<int> &nums, int target);

int main() {

  std::vector<int> nums = {4, 5, 6};
  int target = 10;
  auto indexes = twoSum(nums, target);

  std::cout << "[" << indexes.at(0) << ", " << indexes.at(1) << "]\n";
}

std::vector<int> twoSum(std::vector<int> &nums, int target) {

  std::map<int, int> compliment;

  int counter = 0;
  for (auto num : nums) {
    auto comp = target - num;

    if (compliment.count(comp)) {
      return {counter, compliment.at(comp)};
    }

    compliment[num] = counter;

    counter++;
  }

  return {-1, -1};
}
