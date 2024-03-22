#include <iostream>

const int kMaxm = 23, kMaxn = 1e5 + 100;

int dp[kMaxm][kMaxn];

int Get(int ii, int jj, int kk) {
  return std::max(dp[ii][jj - kk], dp[ii - 1][kk]);
}

int main() {
  int nu;
  int mu;
  std::cin >> nu >> mu;
  if (mu == 0) {
    if (nu == 1) {
      std::cout << 0;
    } else {
      std::cout << -1;
    }
    return 0;
  }
  for (int i = 1; i <= nu; ++i) {
    dp[1][i] = i - 1;
  }
  for (int i = 2; i < kMaxm; ++i) {
    dp[i][1] = 0;
    for (int j = 2; j <= nu; ++j) {
      dp[i][j] = kMaxn;
      int lx = 1;
      int rx = j - 1;
      while (rx - lx > 1) {
        int mx = (rx + lx) / 2;
        if (dp[i][j - mx] >= dp[i - 1][mx]) {
          lx = mx;
        } else {
          rx = mx;
        }
      }
      dp[i][j] = std::min(dp[i][j], 1 + Get(i, j, lx));
      lx = 1;
      rx = j - 1;
      while (rx - lx > 1) {
        int mx = (rx + lx) / 2;
        if (dp[i][j - mx] <= dp[i - 1][mx]) {
          lx = mx;
        } else {
          rx = mx;
        }
      }
      dp[i][j] = std::min(dp[i][j], 1 + Get(i, j, lx));
    }
  }

  mu = std::min(mu, kMaxm - 1);
  std::cout << dp[mu][nu];
}
