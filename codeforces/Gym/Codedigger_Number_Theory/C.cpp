#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    int max_gcd = 0;
    
    //vector<int> visited(n);
    for (int i = 0; i < n - 1; i++) max_gcd = max(max_gcd,__gcd(a[i],a[i + 1]));

    int j;
    int ans = 0;
    for (int i = 0; i < n - 1; ){
        int cur_gcd = __gcd(a[i],a[i + 1]);
        if (cur_gcd == max_gcd){
            j =  i + 2;
            while ((j < n) && (a[j] % cur_gcd == 0)) j++;
            ans = max(ans,j - i);
            i = j;
        }
        else ++i;
    }
    cout << max_gcd << ' ' << ans << '\n';
            
            
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

