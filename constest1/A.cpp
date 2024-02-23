#include <algorithm>
#include <iostream>
#include <vector>

const long long kInf = 1e18 + 7;

int main() {
  int number;
  std::cin >> number;
  std::vector<long long> ar(number);
  std::vector<int> dp(number + 1, number);
  std::vector<int> pr(number + 1, -1);
  for (int i = 0; i < number; ++i) {
    std::cin >> ar[i];
  }
  std::reverse(ar.begin(), ar.end());
  ar.push_back(kInf);
  for (int i = 0; i < number; ++i) {
    int lx = 0;
    int rx = number;
    while (rx - lx > 1) {
      int mx = (rx + lx) / 2;
      if (ar[dp[mx]] > ar[i]) {
        rx = mx;
      } else {
        lx = mx;
      }
    }
    pr[i] = dp[lx];
    dp[rx] = i;
  }
  int lst = 0;
  for (int i = number; i >= 0; --i) {
    if (dp[i] != number) {
      std::cout << i << '\n';
      lst = i;
      break;
    }
  }
  int ptr = dp[lst];
  for (int i = 0; i < lst; ++i) {
    std::cout << number - ptr << ' ';
    ptr = pr[ptr];
  }
  return 0;
}
