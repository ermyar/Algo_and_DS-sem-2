#include <iostream>
#include <vector>

const int kMaxn = 1e4 + 100, kMaxm = 200;

int dp[kMaxm][kMaxn];
int pr[kMaxn][kMaxn];

int main() {
  int number;
  int wes;
  std::cin >> number >> wes;
  std::vector<int> ar(number);
  std::vector<int> br(number);
  for (int i = 0; i < number; ++i) {
    std::cin >> ar[i];
  }
  for (int i = 0; i < number; ++i) {
    std::cin >> br[i];
  }
  for (int i = 0; i < number; ++i) {
    for (int j = 0; j <= wes; ++j) {
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = 0; j <= wes; ++j) {
      if (j + ar[i] <= wes) {
        if (dp[i + 1][j + ar[i]] < dp[i][j] + br[i]) {
          dp[i + 1][j + ar[i]] = dp[i][j] + br[i];
          pr[i + 1][j + ar[i]] = (i + 1);
        }
      }
    }
  }
  // for (int i = 0; i <= number; ++i) {
  //   for (int j = 0; j <= wes; ++j) {
  //     std::cout << dp[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  int ptr = 0;
  for (int i = 0; i <= wes; ++i) {
    if (dp[number][i] > dp[number][ptr]) {
      ptr = i;
    }
  }
  std::vector<int> ans;
  for (int i = 0; i < number; ++i) {
    if (pr[number - i][ptr] > 0) {
      ans.push_back(pr[number - i][ptr]);
      ptr -= ar[pr[number - i][ptr] - 1];
    }
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    std::cout << ans[(int)ans.size() - 1 - i] << '\n';
  }
  return 0;
}