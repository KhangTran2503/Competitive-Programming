#include <bits/stdc++.h>
#define oo int(1e9)
#define all(s) s.begin(), s.end()
using namespace std;
typedef unsigned long long ll;
typedef double db;
const ll MOD = (ll)(1e9) + 7;
ll dp[10001][100][2];
int D;
int n;
string K;
// dp[][][] dp digit

ll calc(int id,int sum_digit,int tight,const string& K){
    if (id == K.size()) return (sum_digit == 0);
    if (dp[id][sum_digit][tight] != -1 && tight == 0) return dp[id][sum_digit][tight];
    int limit = (tight) ? (K[id] - '0'): 9;
    ll ans = 0;
    for (int dig = 0; dig <= limit; dig ++){
        int newtight = ((K[id] - '0') == dig) ? tight : 0;
        ans = (ans + calc(id + 1,(sum_digit + dig) % D,newtight,K) ) % MOD;
    }
    return dp[id][sum_digit][tight] = ans;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> K;
    cin.ignore();
    cin >> D;
    memset(dp,-1,sizeof(dp));
    cout << (calc(0,0,1,K) - 1 + MOD) % MOD;
	return 0;
}
