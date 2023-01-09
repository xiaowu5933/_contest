#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> g(n + 5, -1);
    std::function<int(int, int)> calc = [&](int a, int f) {
      if (g[a] != -1) {
        return g[a];
      }
      if (a == n) {
        return g[a] = 1;
      }
      int ans = 0;
      for (int i = a + 1; i <= std::min(n, a + k); ++i) {
        ans = std::max(ans, calc(i, f ^ 1));
      }
      return g[a] = !ans;
    };
    std::cout << (calc(0, 1) ? "nqson" : "ntanh") << "\n";
  }
  return 0;
}