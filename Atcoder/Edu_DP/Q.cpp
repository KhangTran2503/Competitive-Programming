#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a, h;
vector<ll> fen;
int n;

void update(int id,ll val){
    while (id <= n){
        fen[id] = max(fen[id],val);
        id += (id & -id);
    }
}

ll get(int id){
    ll ans = 0;
    while (id){
        ans = max(ans,fen[id]);
        id -= (id & -id);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n;
    ll ans = 0;
    a.resize(n + 1);
    h.resize(n + 1);
    fen.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++){
        ll val = get(h[i] - 1) + a[i];
        ans = max(ans,val);
        update(h[i],val);
    }
    cout << ans;
    return 0;
}