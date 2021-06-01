#include "bits/stdc++.h"
using namespace std;
void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
    sum += a[i];
  }
  auto check = [&](int g) -> bool {
    int res = 0;
    multiset<int> ms;
    for (int &u : a) {
      ms.insert(u % g);
    }
    while (ms.size() && res <= k) {
      if (*ms.begin() == 0) {
        ms.erase(ms.begin());
        continue;
      } 
      int u = *ms.begin();
      int v = *ms.rbegin();
      ms.erase(ms.begin());
      ms.erase(-- ms.end());
      if (u < g - v) {
        res += u;
        ms.insert((v + u) % g);
      }
      else {
        res += g - v;
        ms.insert((u + v) % g);
      }
    }
    return res <= k && ms.size() == 0;
  };
  int ans = 1;
  for (int i = 1; i * i <= sum; i ++) {
    if (sum % i == 0) {
      if (check(i)) ans = max(ans, i);
      if (check(sum / i)) ans = max(ans, sum / i);
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); int tc = 1;
#ifdef DEBUG  
  freopen("input.txt", "r", stdin); 
#endif
  // cin >> tc;
  while (tc --) { solution(); cout << "\n"; }
}