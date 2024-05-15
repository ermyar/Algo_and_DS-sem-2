#include <algorithm>
#include <iostream>
#include <vector>

const int cMaxn = 4000 + 100;

std::vector<int> gr[cMaxn];
int match[cMaxn][2];
int used[cMaxn][2];

void Dfs(int v, int c) {
  // std::cout << "DFS " << v << ' ' << c << '\n';
  used[v][c] = 1;
  if (c == 1) {
    if (match[v][1] == 0) {
      return;
    }
    if (used[match[v][1]][0] == 0) {
      Dfs(match[v][1], 0);
    }
  } else {
    for (auto u : gr[v]) {
      if (used[u][1] == 0) {
        Dfs(u, 1);
      }
    }
  }
}

int main() {
  int m;
  int n;
  std::cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    int cnt;
    std::cin >> cnt;
    for (int j = 0; j < cnt; ++j) {
      int x;
      std::cin >> x;
      gr[i].push_back(x);
    }
  }
  for (int i = 1; i <= m; ++i) {
    std::cin >> match[i][0];
    if (match[i][0] != 0) {
      match[match[i][0]][1] = i;
      for (size_t j = 0; j < gr[i].size(); ++j) {
        if (gr[i][j] == match[i][0]) {
          for (size_t k = j; k + 1 < gr[i].size(); ++k) {
            std::swap(gr[i][k], gr[i][k + 1]);
          }
          gr[i].pop_back();
          break;
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (match[i][0] == 0) {
      Dfs(i, 0);
    }
  }
  std::vector<int> ans[2];
  for (int i = 1; i <= m; ++i) {
    if (used[i][0] == 0) {
      ans[0].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (used[i][1] == 1) {
      ans[1].push_back(i);
    }
  }
  std::cout << ans[0].size() + ans[1].size() << '\n';
  std::cout << ans[0].size() << ' ';
  for (auto i : ans[0]) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  std::cout << ans[1].size() << ' ';
  for (auto i : ans[1]) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  return 0;
}