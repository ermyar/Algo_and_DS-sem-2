#include <iostream>
#include <vector>

const int kMaxn = 1e4 + 100, kMaxm = 200;

class Task {
  int dp[kMaxm][kMaxn];
  int pr[kMaxn][kMaxn];
  int number;
  int wes;
  std::vector<int> ar;
  std::vector<int> br;

 public:
  void Input() {
    std::cin >> number >> wes;
    ar.resize(number);
    br.resize(number);
    for (int i = 0; i < number; ++i) {
      std::cin >> ar[i];
    }
    for (int i = 0; i < number; ++i) {
      std::cin >> br[i];
    }
  }

  void Calculate() {
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
  }

  void GetAnswer() {
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
  }
};

int main() {
  Task tmp;
  tmp.Input();
  tmp.Calculate();
  tmp.GetAnswer();
  return 0;
}