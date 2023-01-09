#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  std::map<long long, int> c;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++c[a[i]];
  }
  long long min = *std::min_element(a.begin(), a.end());
  long long max = *std::max_element(a.begin(), a.end());
  int ans = c[min];
  if (min != max) {
    ans += c[max];
  }
  std::cout << ans << "\n";
  return 0;
}