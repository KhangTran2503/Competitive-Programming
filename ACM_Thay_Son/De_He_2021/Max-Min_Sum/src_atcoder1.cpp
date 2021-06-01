#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  int n, k;
  cin >> n >> k;
  vector<int64_t> v(n);
  for(int i = 0;i < n;i++) cin >> v[i];
  sort(v.begin(), v.end());
  int64_t mi = 0;
  int64_t ma = 0;
  for(int i = 0;i < n;i++){
    ma += (COM(i, k - 1) * v[i]) % MOD;
    ma %= MOD;
    mi += (COM(n - i - 1, k - 1) * v[i]) % MOD;
    mi %= MOD;
  }
  int64_t ans = ma - mi;
  if(ans < 0) ans += MOD;
  else if(ans >= MOD) ans %= MOD;
  cout << ans << endl;
}
