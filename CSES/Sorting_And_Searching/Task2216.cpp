#include <bits/stdc++.h>
using namespace std;
int n;

// Dilworth theorem 
// so luong day con tang hop thanh = so luong day con giam
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<bool> visit(n + 1,false);
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (!visit[x  - 1]) ans++;
        visit[x] = true;
    }
    cout << ans;
    return 0;
}
