#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

const int KMaxn = 1e6 + 100;

class Graph {
 private:
  int number;
  int mumber;
  std::vector<int> graph[KMaxn];
  int used[KMaxn];
  int tin[KMaxn];
  int tout[KMaxn];
  int timer;
  std::vector<int> bridge;
  std::map<std::pair<int, int>, int> mappa;

 public:
  void Dfs(int vertex_v, int parent) {
    used[vertex_v] = 1;
    ++timer;
    tin[vertex_v] = tout[vertex_v] = timer;
    for (int vertex_u : graph[vertex_v]) {
      if (vertex_u == parent) {
        continue;
      }
      if (used[vertex_u] != 0) {
        tout[vertex_v] = std::min(tout[vertex_v], tin[vertex_u]);
      } else {
        Dfs(vertex_u, vertex_v);
        tout[vertex_v] = std::min(tout[vertex_v], tout[vertex_u]);
        if (tout[vertex_u] > tin[vertex_v]) {
          int val = mappa[{std::min(vertex_u, vertex_v), std::max(vertex_u, vertex_v)}];
          if (val != -1) {
            bridge.push_back(val);
          }
        }
      }
    }
  }

  void Init() {
    std::cin >> number >> mumber;
    for (int i = 0; i < mumber; ++i) {
      int val_x;
      int val_y;
      std::cin >> val_x >> val_y;
      if (val_x > val_y) {
        std::swap(val_x, val_y);
      }
      graph[val_x].push_back(val_y);
      graph[val_y].push_back(val_x);
      if (mappa[{val_x, val_y}] == 0) {
        mappa[{val_x, val_y}] = i + 1;
      } else {
        mappa[{val_x, val_y}] = -1;
      }
    }
  }

  void Get_bridge() {
    for (int i = 1; i <= number; ++i) {
      if (used[i] == 0) {
        Dfs(i, -1);
      }
    }
    std::sort(bridge.begin(), bridge.end());  
    for (int val_i : bridge) {
      std::cout << val_i << ' ';
    }
  }
};



int main() {
  Graph tmp;
  tmp.Init();
  tmp.Get_bridge();
  return 0;
}