#include <bits/stdc++.h>
constexpr int P = 1E9 + 7;
int normalize(int x) {
  if (x >= P) {
    x -= P;
  }
  if (x < 0) {
    x += P;
  }
  return x;
}
template<typename T>
T power(T a, long long n) {
  T res = 1;
  for (; n; n /= 2, a *= a) {
    if (n & 1) {
      res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int x = 0) : x(normalize(x)) {}
  Z(long long x) : x(normalize(x % P)) {}
  int val() const {
    return x;
  }
  Z operator-() const {
    return Z(normalize(P - x));
  } 
  Z inv() const {
    return power(*this, P - 2);
  } 
  Z& operator*=(const Z& rhs) {
    x = x * 1ll * rhs.x % P;
    return *this;
  } 
  Z& operator+=(const Z& rhs) {
    x = normalize(x + rhs.x);
    return *this;
  }
  Z& operator-=(const Z& rhs) {
    x = normalize(x - rhs.x);
    return *this;
  }
  Z& operator/=(const Z& rhs) {
    return *this *= rhs.inv();
  }
  friend Z operator*(const Z& lhs, const Z& rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z& lhs, const Z& rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z& lhs, const Z& rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z& lhs, const Z& rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  // sub1
  while (tt--) {
    long long n;
    std::cin >> n;
    std::pair<double, long long> ans;
    for (long long i = std::sqrt(n); i >= 1; --i) {
      if (n % i == 0) {
        // i ^ (n / i)
        double t = (double) (n / i) * std::log(i);
        ans = std::max(ans, std::make_pair(t, i));
      }
    }
    if (ans.second == 1) {
      std::cout << "OK\n";
    } else {
      std::cout << power(Z(ans.second), n / ans.second).val() << "\n";
    }
  }
  return 0;
}