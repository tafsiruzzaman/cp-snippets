#include<bits/stdc++.h>
using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

long long get_rand(long long l, long long r) {
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // Generate numbers between 1 and 1000 for better chance of finding mismatch
  int n = get_rand(1, 10000);
  int q = get_rand(1, 10000);
  cout << n << " " << q << "\n";
  for (int i = 0; i < n; i++) {
    cout << get_rand(1, 1e9) << " \n"[i == n - 1];
  }
  while (q--) {
    int t = get_rand(1, 2);
    cout << t << " ";
    if (t == 1) {
      int l = get_rand(1, n), r = get_rand(1, n), x = get_rand(1, 1e9);
      if (l > r) swap(l, r);
      cout << l << " " << r << " " << x << "\n";
    } else {
      int l = get_rand(1, n), r = get_rand(1, n);
      if (l > r) swap(l, r);
      cout << l << " " << r << "\n";
    }
  }
  return 0;
}