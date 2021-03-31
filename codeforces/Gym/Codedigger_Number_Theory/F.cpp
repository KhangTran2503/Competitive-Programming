#include <bits/stdc++.h>
using namespace std;
int n, x;

int fastpow(int a,int b){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % x;
        a = (a*a) % x;
        b >>= 1;
    }
    return ans;
}

void solve(){
    cin >> n >> x;
    vector<int> pos_mod(x,-1);
    vector<int> inv_mod(x);

    for (int i = 1; i < x; i++) inv_mod[i] = fastpow(i,x - 2);

    pos_mod[1] = 0;
    int cur_mod = 1;    

    int ans = 0;
    int ans_len = n + 1;
    for (int i = 1; i <= n; i++){
        int ai;
        cin >> ai;
        cur_mod = (cur_mod*ai) % x;
        for (int m = x - 1; m > 0; m--){
            int pre_mod = (cur_mod*inv_mod[m]) % x;
            if (pos_mod[pre_mod] > -1){
                if (m  >= ans){
                    if (m == ans)  ans_len = min(ans_len,i - pos_mod[pre_mod]);
                    else ans_len = i - pos_mod[pre_mod];
                    ans = m;
                    //cout << m << ' ' << pos_mod[pre_mod] << ' ' << i << '\n';
                    break;
                }
            }
        }    
        pos_mod[cur_mod] = i;
    }
    cout << ans << ' ' << ans_len << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
