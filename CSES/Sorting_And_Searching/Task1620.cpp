#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
int n;
ll t;
vector<ll> k;

bool check(ll mid){
    ll total_time = 0;
    for (ll ki: k){
        total_time += (mid/ki);
        if (total_time >= t) return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    k.resize(n);
    for (ll &ki: k) cin >> ki;

    ll low = 0, high = INF;
    ll res = 0;
    while (low <= high){
        ll mid = (low + high) >> 1;
        if (check(mid)){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << res;
    return 0;
}
