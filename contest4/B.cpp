#include <algorithm>
#include <iostream>
#include <vector>

struct Dsu {
 private:
  struct Node {
    int sz = 1;
    int parent = -1;
  };

  std::vector<Node> ar_;

 public:
  Dsu(int n) { ar_.resize(n + 1); }

  bool Union(int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x == y) {
      return false;
    }
    if (ar_[x].sz > ar_[y].sz) {
      std::swap(x, y);
    }
    ar_[y].sz += ar_[x].sz;
    ar_[x].parent = y;
    return true;
  }

  int Get(int x) {
    if (ar_[x].parent == -1) {
      return x;
    }
    return Get(ar_[x].parent);
  }
};

struct Edge {
  int u;
  int v;
  int weight;
};

bool operator<(const Edge& a, const Edge& b) { return a.weight < b.weight; }

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<Edge> he(m);
  for (int i = 0; i < m; ++i) {
    int x;
    int y;
    int z;
    std::cin >> x >> y >> z;
    he[i] = Edge{x, y, z};
  }
  Dsu osu(n);
  std::sort(he.begin(), he.end());
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (osu.Union(he[i].u, he[i].v)) {
      ans += he[i].weight;
    }
  }
  std::cout << ans;
  return 0;
}