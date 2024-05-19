#include <algorithm>
#include <iostream>
#include <vector>

const int KMaxn = 1e6 + 100;

class Graph {
 private:
  int number;
  int mumber;
  std::vector<int> graph[KMaxn];
  std::vector<int> rgraph[KMaxn];
  std::vector<int> stst;
  int color[KMaxn];

  void Dfs(int vertex) {
    color[vertex] = 1;
    for (int uuuu : graph[vertex]) {
      if (color[uuuu] == 1) {
        continue;
      }
      Dfs(uuuu);
    }
    stst.push_back(vertex);
  }

  void Dfs1(int vertex, int cmp) {
    color[vertex] = cmp;
    for (int vertex_u : rgraph[vertex]) {
      if (color[vertex_u] != 0) {
        continue;
      }
      Dfs1(vertex_u, cmp);
    }
  }

 public:

  void Input() {
    std::cin >> number >> mumber;
    for (int i = 0; i < mumber; ++i) {
      int xxxx;
      int yyyy;
      std::cin >> xxxx >> yyyy;
      graph[xxxx].push_back(yyyy);
      rgraph[yyyy].push_back(xxxx);
    }
  }

  void Condens() {
    for (int i = 1; i <= number; ++i) {
      if (color[i] == 0) {
        Dfs(i);
      }
    }
    for (int i = 1; i <= number; ++i) {
      color[i] = 0;
    }
    std::reverse(stst.begin(), stst.end());
    int cmp = 0;
    for (auto iiii : stst) {
      if (color[iiii] == 0) {
        cmp++;
        Dfs1(iiii, cmp);
      }
    }
    std::cout << cmp << '\n';
    for (int i = 1; i <= number; ++i) {
      std::cout << color[i] << ' ';
    }
  }
};

int main() {
  Graph tmp;
  tmp.Input();
  tmp.Condens();
  return 0;
}