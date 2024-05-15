#include <iostream>
#include <set>
#include <vector>

const int cMaxn = 1e5 + 100, cInf = 2009000999;

std::vector<std::pair<int, int>> gr[cMaxn];

void Solve() {
  int n;
  int m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u;
    int v;
    int e;
    std::cin >> u >> v >> e;
    gr[u].push_back({v, e});
    gr[v].push_back({u, e});
  }
  int kk;
  std::cin >> kk;
  std::vector<int> d(n, cInf);
  d[kk] = 0;
  std::set<std::pair<int, int>> st;
  st.insert({0, kk});
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
  for (auto i : d) {
    std::cout << i << ' ';
  }
  for (int i = 0; i < n; ++i) {
    gr[i].clear();
  }
}

int main() {
  int t = 1;
  std::cin >> t;
  while ((t--) != 0) {
    Solve();
  }
}