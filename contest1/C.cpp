#include <iostream>

const int kMaxm = 23, kMaxn = 1e5 + 100;

class DynamicProgramming {
 private:
  int dp_[kMaxm][kMaxn];
  int number_;
  int mom_;

  int Get(int ii, int jj, int kk) {
    return std::max(dp_[ii][jj - kk], dp_[ii - 1][kk]);
  }

  int BinSearch(int i, int j, int k) {
    int lx = 1;
    int rx = j - 1;
    while (rx - lx > 1) {
      int mx = (rx + lx) / 2;
      if (((dp_[i][j - mx] - dp_[i - 1][mx]) * k) >= 0) {
        lx = mx;
      } else {
        rx = mx;
      }
    }
    return lx;
  }

 public:
  void InputData() {
    std::cin >> number_ >> mom_;
  }

  void Calculate() {
    if (mom_ == 0) {
      if (number_ == 1) {
        std::cout << 0;
      } else {
        std::cout << -1;
      }
      return;
    }
    for (int i = 1; i <= number_; ++i) {
      dp_[1][i] = i - 1;
    }
    for (int i = 2; i < kMaxm; ++i) {
      dp_[i][1] = 0;
      for (int j = 2; j <= number_; ++j) {
        dp_[i][j] = kMaxn;
        int lx = BinSearch(i, j, 1);
        dp_[i][j] = std::min(dp_[i][j], 1 + Get(i, j, lx));
        lx = BinSearch(i, j, -1);
        dp_[i][j] = std::min(dp_[i][j], 1 + Get(i, j, lx));
      }
    }

    mom_ = std::min(mom_, kMaxm - 1);
    std::cout << dp_[mom_][number_];
  }
};

int main() {
  DynamicProgramming task;
  task.InputData();
  task.Calculate();
}
