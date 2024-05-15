#include <algorithm>
#include <iostream>
#include <vector>

const long long cInf = 1e18, cMax = 100000;

struct Edge {
  int from, to, weight;

  Edge(int xx, int yy, int ww) : from(xx), to(yy), weight(ww) {}
};

void Solve() {
  std::vector<Edge> gr;
  int number;
  std::cin >> number;
  for (int i = 1; i <= number; ++i) {
    for (int j = 1; j <= number; ++j) {
      int xx;
      std::cin >> xx;
      if (xx == cMax) {
        continue;
      }
      gr.push_back(Edge(i, j, xx));
      // std::cout << i << ' ' << j << ' ' << xx << '\n';
    }
  }
  for (int i = 1; i <= number; ++i) {
    std::vector<long long> parent(number + 1, -1);
    std::vector<long long> dist(number + 1, cInf);
    dist[i] = 0;
    int ptr = -1;
    for (int i = 0; i < number; ++i) {
      ptr = -1;
      for (Edge j : gr) {
        if (dist[j.from] < cInf) {
          if (dist[j.to] > (dist[j.from] + j.weight)) {
            dist[j.to] = dist[j.from] + j.weight;
            ptr = j.to;
            parent[j.to] = j.from;
          }
        }
      }
    }
    if (ptr == -1) {
      continue;
    }
    std::vector<int> used(number + 1, 0);
    while (used[ptr] != 1) {
      used[ptr]++;
      ptr = parent[ptr];
    }
    std::vector<int> ans;
    while (ans.empty() || (ptr != ans[0])) {
      ans.push_back(ptr);
      ptr = parent[ptr];
    }
    ans.push_back(ptr);
    std::reverse(ans.begin(), ans.end());
    std::cout << "YES\n";
    std::cout << ans.size() << '\n';
    for (int i : ans) {
      std::cout << i << ' ';
    }
    return;
  }
  std::cout << "NO";
}

int main() {
  int t = 1;
  // std::cin >> t;
  while ((t--) != 0) {
    Solve();
  }
}