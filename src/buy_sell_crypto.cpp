#include <algorithm>
#include <iostream>
#include <vector>
int maxProfit(std::vector<int> &prices);

int main() {

  std::vector<int> prices = {10, 1, 5, 6, 7, 1};
  int mx_profit = maxProfit(prices);
  std::cout << "Max profit : " << mx_profit << "\n";

  prices = {10, 8, 7, 5, 2};
  mx_profit = maxProfit(prices);
  std::cout << "Max profit : " << mx_profit << "\n";

  return 0;
}

int maxProfit(std::vector<int> &prices) {

  int max_profit = 0;

  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      if (prices.at(j) > prices.at(i)) {
        max_profit = std::max(max_profit, (prices.at(j) - prices.at(i)));
      }
    }
  }
  return max_profit;
}
