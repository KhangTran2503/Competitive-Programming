#include <bits/stdc++.h>
using namespace std;
vector<int> a(4), cnt(4);
vector<int> ans;
bool ok = false;
// check x - 1 truoc
void check(int u){
    if (cnt[u] == 0) return;
    cnt[u]--;
    ans.push_back(u);
    if (int(ans.size()) == a[0] + a[1] + a[2] + a[3]){
        cout << "YES\n";
        for (int x: ans) cout << x << ' ';
        ok = true;
    }

    if (u == 0) {
        check(1);
        return;
    }    
    if (u == 3) {
        check(2);
        return;
    }    
    if (u == 1){
        if (cnt[0]) check(0);
        else check(2);
        return;
    }
    if (u == 2){
        if (cnt[1]) check(1);
        else check(3);
        return;
    }
    
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    for (int x = 0; x < 4; x++){
        cnt = a;
        check(x);
        if (ok) return 0;
        ans.clear();
    }

    cout << "NO";    
    return 0;
}