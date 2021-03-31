#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int &pi: p) cin >> pi;


    vector<bool> dp(n + 1,true);
    dp[0] = false;
    for (int i = 1; i <= n; i++){
        bool ok = false;
        for (int pi: p)
            if (i >= pi && !dp[i - pi]){
                ok = true;
                break;
            }
        dp[i] = ok;
    }

    for (int i = 1; i <= n; ++i)
        if (dp[i]) cout << 'W';
        else cout << 'L';
    
    return 0;
}
