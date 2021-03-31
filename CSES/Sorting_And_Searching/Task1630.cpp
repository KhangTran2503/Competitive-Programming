#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<pair<int,int>> task(n);
    
    for (pair<int,int> &t: task) cin >> t.first >> t.second;
    sort(task.begin(),task.end());

    ll ans = 0;
    ll finish = 0;
    for (pair<int,int> t: task){
        finish += (ll)t.first;
        ans += (ll)(t.second - finish);
    }
    cout << ans;
    return 0;
}
