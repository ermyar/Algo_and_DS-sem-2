#include <iostream>
#include <set>
#include <vector>

const int cMaxn = 1e5 + 100, cInf = 2009000999;

struct Graph {
 private:
  int vertex;
  int edges;
  std::vector<std::pair<int, int>> gr[cMaxn];

 public:
  void Init() {
    std::cin >> vertex >> edges;
    for (int i = 0; i < edges; ++i) {
      int u;
      int v;
      int e;
      std::cin >> u >> v >> e;
      gr[u].push_back({v, e});
      gr[v].push_back({u, e});
    }
  }

  std::vector<int>& Diikstra(int start) {
    std::vector<int> d(vertex, cInf);
    d[start] = 0;
    std::set<std::pair<int, int>> st;
    st.insert({0, start});
    while (!st.empty()) {
      auto [x, y] = *st.begin();
      st.erase(st.begin());
      for (auto [u, e] : gr[y]) {
        if (d[u] > (e + d[y])) {
          st.erase({d[u], u});
          d[u] = d[y] + e;
          st.insert({d[u], u});
        }
      }
    }
    return d;
  }
};

int main() {
  int t = 1;
  std::cin >> t;
  while ((t--) != 0) {
    Graph tmp;
    tmp.Init();
    int start;
    std::cin >> start;
    auto distance = tmp.Diikstra(start);
    for (auto i : distance) {
      std::cout << i << ' ';
    }
  }
}