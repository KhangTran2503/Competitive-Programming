#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(const char &x,const char &y){
    if (x == y){
        if (x == '*') return true;
        return false;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<char> a(n);
    for (char &x: a) cin >> x;
    
    //a.erase(unique(a.begin(),a.end(),cmp),a.end());
    //for (char x: a) cout << x;
    //cout << '\n';

    if (a.empty()){
        cout << 0 << '\n';
        return;
    }

    vector<int> dis;
    for (int i =0 ; i < a.size(); i++)
        if (a[i] == '*') dis.push_back(i);

    if (dis.empty()){
        cout << 0 << '\n';
        return;
    }

    //for (int x: dis) cout << x << ' ';
    for (int i = 0; i < (int)dis.size(); i++) dis[i] -= i;
    sort(dis.begin(),dis.end());

    int mid = dis[(int)dis.size()/2];
    ll ans = 0;
    for (int x: dis)
        ans += (ll)abs(x - mid);

   cout << ans << '\n';


}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
