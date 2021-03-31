#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 9;
ll memo[305][305][2];
string T,s ;
int q;
int n;

void add(ll &a,ll b){
    a += b;
    if (a >= Mod) a %= Mod;
}

ll dp(int l,int r,int val){
    if (l == r){
        return memo[l][r][val] = (T[l] - '0' == val);
    }
    ll &ans = memo[l][r][val];
    if (ans != -1) return ans;
    ans = 0;

    for (int k = l; k < r; k++){
        if (s[k] == 'a'){
            if (val){
                add(ans,(dp(l,k,1)*dp(k + 1,r,1)) % Mod);
            }
            else {
                add(ans,(dp(l,k,0)*dp(k + 1,r,1)) % Mod);
                add(ans,(dp(l,k,1)*dp(k + 1,r, 0)) % Mod);
                add(ans,(dp(l,k,0)*dp(k + 1,r,0)) % Mod);
            }
        }
        else if (s[k] == 'o'){
            if (!val){
                add(ans,(dp(l,k,0)*dp(k + 1,r,0)) % Mod);
            }
            else {
                add(ans,(dp(l,k,0)*dp(k + 1,r,1)) % Mod);
                add(ans,(dp(l,k,1)*dp(k + 1,r, 0)) % Mod);
                add(ans,(dp(l,k,1)*dp(k + 1,r,1)) % Mod);
            }
        }
        else{
            if (!val){
                add(ans,(dp(l,k,0)*dp(k + 1,r,0)) % Mod);
                add(ans,(dp(l,k,1)*dp(k + 1,r,1)) % Mod);
            }
            else {
                add(ans,(dp(l,k,0)*dp(k + 1,r,1)) % Mod);
                add(ans,(dp(l,k,1)*dp(k + 1,r, 0)) % Mod);  
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T ;
    cin >> s;
    cin >> q;
    n = T.size();
    memset(memo,-1,sizeof(memo));
    dp(0,n - 1,0);
    dp(0,n - 1,1);
    while (q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        string x;
        cin >> x;
        if (x == "true") cout << dp(l,r,1) << '\n';
        else cout << dp(l,r,0) << '\n';
    }
    return 0;
}