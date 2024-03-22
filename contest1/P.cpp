#include <iostream>
#include <vector>

const int kMaxn = (1 << 15), kMaxm = 120, kMod = 1e9 + 7;

int Mood(int xx) {
  xx %= kMod;
  if (xx < 0) {
    xx += kMod;
  }
  return xx;
}

int ar[kMaxm][kMaxm];
long long dp[kMaxm][kMaxn];

bool Check(int ii, int mask, int nigger) {
  for (int j = 0; j < nigger; ++j) {
    if ((mask & (1 << j)) > 0) {
      if (ar[j][ii] == 2) {
        return false;
      }
    } else {
      if (ar[j][ii] == 1) {
        return false;
      }
    }
  }
  return true;
}

void Compute(int nigger, int migga, int* mapa) {
  for (int i = 0; i + 1 < migga; ++i) {
    for (int mask = 0; mask < (1 << nigger); ++mask) {
      if (dp[i][mask] == 0) {
        continue;
      }
      if (mask == mapa[0] || mask == mapa[1]) {
        if (Check(i + 1, mapa[0], nigger)) {
          dp[i + 1][mapa[0]] = Mood(dp[i + 1][mapa[0]] + dp[i][mask]);
        }
        if (Check(i + 1, mapa[1], nigger)) {
          dp[i + 1][mapa[1]] = Mood(dp[i + 1][mapa[1]] + dp[i][mask]);
        }
        continue;
      }
      int ptsr = (mask ^ ((1 << nigger) - 1));
      if (Check(i + 1, ptsr, nigger)) {
        dp[i + 1][ptsr] = Mood(dp[i + 1][ptsr] + dp[i][mask]);
      }
    }
  }
}

int main() {
  int nigger;
  int migga;
  std::cin >> nigger >> migga;
  for (int i = 0; i < nigger; ++i) {
    for (int j = 0; j < migga; ++j) {
      char cx;
      std::cin >> cx;
      if (cx == '+') {
        ar[i][j] = 1;
      } else if (cx == '-') {
        ar[i][j] = 2;
      }
    }
  }

  int mapa[2];
  mapa[0] = mapa[1] = 0;

  for (int i = 0; i < nigger; ++i) {
    mapa[i % 2] += (1 << i);
  }

  for (int i = 0; i < (1 << nigger); ++i) {
    if (Check(0, i, nigger)) {
      dp[0][i] = 1;
    }
  }

  Compute(nigger, migga, mapa);

  int ans = 0;
  for (int i = 0; i < (1 << nigger); ++i) {
    ans = Mood(ans + dp[migga - 1][i]);
  }
  std::cout << ans;
}