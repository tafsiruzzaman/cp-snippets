#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using dt = array<int, 2>;

void test() {
  int n, q;
  cin >> n >> q;

  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      for (int i = l; i <= r; i++) {
        v[i] = x;
      }
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      ll tot = 0;
      for (int i = l; i <= r; i++) {
        tot = tot ^ v[i];
      }
      cout << tot << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  
  // cin >> T;
  for (int i = 1; i <= T; i++) {
    test();
  }
  return 0;
}