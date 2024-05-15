#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

const int KMaxn = 1e6 + 100;

std::vector<int> graph[KMaxn];
int used[KMaxn];
int tin[KMaxn];
int tout[KMaxn];
int timer;
std::vector<int> bridge;
std::map<std::pair<int, int>, int> mappa;

void Dfs(int vertex, int parent) {
  used[vertex] = 1;
  ++timer;
  tin[vertex] = tout[vertex] = timer;
  for (int uuuu : graph[vertex]) {
    if (uuuu == parent) {
      continue;
    }
    if (used[uuuu] != 0) {
      tout[vertex] = std::min(tout[vertex], tin[uuuu]);
    } else {
      Dfs(uuuu, vertex);
      tout[vertex] = std::min(tout[vertex], tout[uuuu]);
      if (tout[uuuu] > tin[vertex]) {
        int val = mappa[{std::min(uuuu, vertex), std::max(uuuu, vertex)}];
        if (val != -1) {
          bridge.push_back(val);
        }
      }
    }
  }
}

int main() {
  int number;
  int mumber;
  std::cin >> number >> mumber;
  for (int i = 0; i < mumber; ++i) {
    int xxxx;
    int yyyy;
    std::cin >> xxxx >> yyyy;
    if (xxxx > yyyy) {
      std::swap(xxxx, yyyy);
    }
    graph[xxxx].push_back(yyyy);
    graph[yyyy].push_back(xxxx);
    if (mappa[{xxxx, yyyy}] == 0) {
      mappa[{xxxx, yyyy}] = i + 1;
    } else {
      mappa[{xxxx, yyyy}] = -1;
    }
  }
  for (int i = 1; i <= number; ++i) {
    if (used[i] == 0) {
      Dfs(i, -1);
    }
  }
  std::sort(bridge.begin(), bridge.end());  
  for (int iiii : bridge) {
    std::cout << iiii << ' ';
  }
  return 0;
}