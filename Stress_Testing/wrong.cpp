#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using dt = array<int, 2>;

void test() {
  ll n;
  cin >> n;

  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cout << max(v[0], v[1] - v[0]) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  
  cin >> T;
  for (int i = 1; i <= T; i++) {
    test();
  }
  return 0;
}