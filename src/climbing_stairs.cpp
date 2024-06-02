#include <iostream>
int climbStairs(int n);
int climbStairsDP(int n, int *memory);
int main() {

  int k = 4;
  int steps = climbStairs(k);
  int mem[k + 1];

  for (int i = 0; i <= k; i++) {
    mem[i] = 0;
  }
  int steps1 = climbStairsDP(k, mem);
  std::cout << "Total steps of " << k << " stairs : " << steps << "\n";
  std::cout << "Total steps of " << k << " stairs (DP) : " << steps1 << "\n";

  return 0;
}

int climbStairsDP(int n, int *memory) {
  if (n < 0)
    return 0;
  if (n == 0) {
    memory[n] = 1;
    return 1;
  }
  if (memory[n] == 0)
    memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
  return memory[n];
}

int climbStairs(int n) {

  if (n < 0)
    return 0;
  if (n == 0)
    return 1;

  return climbStairs(n - 1) + climbStairs(n - 2);
}
