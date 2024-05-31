#include <iostream>
#include <map>
#include <string>
bool isAnagram(std::string s, std::string t);

int main() {

  auto is_anagram = isAnagram("abcde", "eddba");
  std::cout << is_anagram << "\n";
  return 0;
}

bool isAnagram(std::string s, std::string t) {
  std::map<int, int> seenCount;

  if (s.length() != t.length())
    return false;

  for (int i = 0; i < s.length(); i++) {

    if (seenCount.count(s.at(i))) {
      seenCount[s.at(i)] = seenCount[s.at(i)] + 1;
    } else {
      seenCount[s.at(i)] = 1;
    }

    if (seenCount.count(t.at(i))) {
      seenCount[t.at(i)] = seenCount[t.at(i)] - 1;
    } else {
      seenCount[t.at(i)] = -1;
    }
  }

  for (int i = 0; i < s.length(); i++) {
    if (seenCount[s.at(i)] != 0)
      return false;
  }

  return true;
}
