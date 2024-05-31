
#include <exception>
#include <experimental/iterator>
#include <iostream>
#include <map>
#include <vector>

bool containsDuplicate(std::vector<int> &nums);
int main() {
  std::cout << "Running contains duplicate\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 6};
  auto contains = containsDuplicate(nums);

  std::cout << "Vector : ";
  copy(nums.begin(), nums.end(),
       std::experimental::make_ostream_joiner(std::cout, " "));
  std::cout << "\n";
  std::cout << "contains duplicate : " << (contains ? "Yes" : "No") << "\n";
  std::cout << "Finished running contains duplicate\n";
  return 0;
}

/*
 * basic version using map
 *
 * */

bool containsDuplicate(std::vector<int> &nums) {

  std::map<int, bool> seen;

  for (auto num : nums) {
    if (seen.count(num)) {
      return true;
    } else {
      seen[num] = true;
    }
  }
  return false;
}
