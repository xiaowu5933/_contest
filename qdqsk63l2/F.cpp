#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  long long k;
  std::cin >> n >> k;
  std::vector<long long> f;
  f.push_back(0);
  std::vector<long long> a(n + 1, 0);
  long long sum = 0;
  std::pair<int, int> ans = {-1, -1};
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] += a[i - 1];
    f.push_back(a[i]);
    int l = std::lower_bound(f.begin(), f.end(), a[i] - k) - f.begin();
    long long new_s = a[i] - a[l];
    if (new_s > sum) {
      sum = new_s;
      // std::cout << sum << " " << i << " " << l << "\n";
      ans = std::make_pair(l, i - l);
    }
  }
  std::cout << ans.first + 1 << " " << ans.second << "\n";
  return 0;
}