#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

const long long cMaxn = 4000 + 100, cInf = __LONG_LONG_MAX__;

struct Graph {
 private:
  struct Edge {
    long long to;
    long long flow;
    long long capacity;
    long long cost;
    long long GetCap() const { return capacity - flow; }
  };

  long long n;
  long long m;
  long long parent[cMaxn];
  long long dist[cMaxn];
  long long minflow[cMaxn];
  std::vector<Edge> lst;
  std::vector<long long> gr[cMaxn];

  void AddEdge(long long v, long long u, long long cap, long long cost) {
    gr[v].push_back(lst.size());
    lst.push_back({u, 0, cap, cost});
    gr[u].push_back(lst.size());
    lst.push_back({v, 0, 0, -cost});
  }

  long long Deikstra(long long n) {
    std::set<std::pair<long long, long long>> st;
    st.insert({0, 1});
    for (long long i = 0; i <= n; ++i) {
      parent[i] = -1;
      dist[i] = cInf;
      minflow[i] = cInf;
    }
    dist[1] = 0;
    while (!st.empty()) {
      auto [x, v] = *st.begin();
      st.erase(st.begin());
      for (auto ind : gr[v]) {
        if (lst[ind].GetCap() == 0) {
          continue;
        }
        long long u = lst[ind].to;
        if ((lst[ind].cost + dist[v]) < dist[u]) {
          st.erase({dist[u], u});
          dist[u] = lst[ind].cost + dist[v];
          parent[u] = ind;
          minflow[u] = std::min(minflow[v], lst[ind].GetCap());
          st.insert({dist[u], u});
        }
      }
    }
    if (dist[n] == cInf) {
      return 0;
    }
    long long ptr = n;
    long long val = minflow[n];
    while (1 < ptr) {
      // std::cout << ptr << ' ';
      lst[parent[ptr]].flow += val;
      lst[parent[ptr] ^ 1].flow -= val;
      ptr = lst[parent[ptr] ^ 1].to;
    }
    val *= dist[n];
    return val;
  }
  
 public:
  void Init() {
    std::cin >> n >> m;
    for (long long i = 0; i < m; ++i) {
      long long x;
      long long y;
      long long cap;
      long long cost;
      std::cin >> x >> y >> cap >> cost;
      AddEdge(x, y, cap, cost);
    }
  }

  void GetAnswer() {
    long long tmp = Deikstra(n);
    long long ans = 0;
    while (tmp > 0) {
      ans += tmp;
      tmp = Deikstra(n);
    }
    std::cout << ans;
  }
};

int main() {
  Graph tmp;
  tmp.Init();
  tmp.GetAnswer();
  return 0;
}