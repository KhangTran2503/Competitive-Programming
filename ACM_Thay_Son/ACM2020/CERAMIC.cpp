#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod_base = 517;
typedef tuple<int,int,int> tup;
int n;
vector<ll> Hash(50001);
vector<ll> prefix;
vector<tuple<int,int,int>> ans;


void update(int k){
    int cnt1 = 1, cnt2 = 0;
    ll val1 = prefix[k], val2 = 0LL;

    for (int i = k; i <= n - k; i+=k){
        ll tmp = prefix[i + k] - prefix[i];
        if (tmp == val1) cnt1++;
        else {
            if (cnt2 == 0){
                cnt2++;
                val2 = tmp;
            }
            else if (tmp == val2) cnt2++;
                 else return;
        }
    }

    //cout << cnt1 << ' ' << cnt2 << '\n';
    if (cnt1 > 0 && cnt2 > 0) ans.emplace_back(k,cnt1,cnt2);

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    Hash[0] = 1;
    for (int i = 1; i <= 50000; i++) Hash[i] = Hash[i - 1]*mod_base;

    prefix.assign(n + 1,0);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + Hash[x];
    }

    for (int divi = 2; divi <= n/2; divi++)
        if (n % divi == 0) update(divi);

    if (ans.empty()) cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for (tup t: ans){
            int k, p, q;
            tie(k,p,q) = t;
            cout << k << ' ' << p << ' ' << q << '\n';
        }
    }
    return 0;
}
