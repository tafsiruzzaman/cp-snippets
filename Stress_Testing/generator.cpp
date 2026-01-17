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
  int t = get_rand(1, 100);
  cout << t << "\n";
  while (t--) {
    int n = get_rand(2, 2000);
    cout << n << "\n";
    set<int> st;
    while (st.size() < n) {
      st.insert(get_rand(1, 1e9));
    }
    vector<int> v(st.begin(), st.end());
    for (int i = 0; i < n; i++) {
      cout << v[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}