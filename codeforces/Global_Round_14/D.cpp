#include <bits/stdc++.h>
using namespace std;
int n, l, r;
vector<int> cnt;

void solve(){
    cin >> n >> l >> r;
    cnt.assign(n + 1,0);
    int x;
    for (int i = 0; i < l; i++){
        cin >> x;
        cnt[x]++;
    }

    for (int i = l; i < n; i++){
        cin >> x;
        cnt[x]--;
    }

    int ans =0;
    int pos = 0;
    int neg = 0;
    for (int i = 1; i <= n; i++){
        if (cnt[i] > 0) pos += cnt[i];
        if (cnt[i] < 0) neg += (-cnt[i]);
    }

    ans += min(pos,neg);
    pos -= ans;
    neg -= ans;

    if (pos){
        for (int i = 1; i <= n; i++)
            if (cnt[i] > 0){
                int tmp = min(cnt[i],pos);
                int sub = tmp/2;
                ans += sub;
                cnt[i] -= 2*sub;
                pos -= 2*sub;
            }
        ans += pos;
        
    }

    if (neg){
        for (int i = 1; i <= n; i++)
            if (cnt[i] < 0){
                int tmp = min(-cnt[i],neg);
                int sub = tmp/2;
                ans += sub;
                cnt[i] += 2*sub;
                neg -= 2*sub;
            }
        ans += neg;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
