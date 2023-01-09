#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::getline(std::cin >> std::ws, s);
    assert(s.size());
    std::reverse(s.begin(), s.end());
    std::string g;
    bool f = true;
    char last;
    for (char c : s) {
      if (c == ' ') {
        if (!f) {
          g += last;
        }
        f = false;
        continue;
      }
      if (f) {
        g += (char) (std::tolower(c));
      }
      last = (char) (std::tolower(c));
    }
    assert(g.back() != ' ');
    if (!f) {
      g += last;
    }
    std::reverse(g.begin(), g.end());
    std::cout << "hello " << g << "\n";
  }
  return 0;
}