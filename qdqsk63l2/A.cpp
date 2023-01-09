#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  long long x;
  std::cin >> n >> x;
  std::map<long long, bool> mp;
  for (int i = 0; i < n; ++i) {
    long long a;
    std::cin >> a;
    if (mp[x - a]) {
      std::cout << std::min(a, x - a) << " " << std::max(a, x - a) << "\n";
    }
    mp[a] = true;
  }
  return 0;
}