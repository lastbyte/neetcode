#include <algorithm>
#include <iostream>
#include <map>
#include <string>
int lengthOfLongestSubstring(std::string s);
int main() {

  std::string test_str = "zxyzxyz";
  int substr_length = lengthOfLongestSubstring(test_str);
  std::cout << "Longest substring without duplicate characters : "
            << substr_length << "\n";

  test_str = "xxxx";
  substr_length = lengthOfLongestSubstring(test_str);
  std::cout << "Longest substring without duplicate characters : "
            << substr_length << "\n";

  test_str = "pwwkew";
  substr_length = lengthOfLongestSubstring(test_str);
  std::cout << "Longest substring without duplicate characters : "
            << substr_length << "\n";

  return 0;
}

int lengthOfLongestSubstring(std::string s) {

  if (s.length() == 0) {
    return 0;
  }

  std::map<int, int> charCount = std::map<int, int>();

  int w_start = 0, w_end = 0, str_length = 0;

  while (w_end < s.length()) {

    if (charCount.count(s.at(w_end))) {
      if (charCount[s.at(w_end)] == 1) {
        charCount[s.at(w_end)] = 0;
        str_length = std::max(str_length, w_end - w_start);
        w_start++;
        w_end = w_start;
      } else {
        charCount[s.at(w_end)] = 1;
        w_end++;
      }
    } else {
      charCount[s.at(w_end)] = 1;
      w_end++;
    }
  }

  if (w_start != w_end) {
    str_length = std::max(str_length, w_end - w_start);
  }

  return str_length;
}
