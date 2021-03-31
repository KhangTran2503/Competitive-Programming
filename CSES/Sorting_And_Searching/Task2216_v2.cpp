#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    int last = 0;
    for (int i = 1; i <= n; i++){
        if (pos[i] < last) ans++;
        last = pos[i];
    }
    cout << ans;
    return 0;
}
