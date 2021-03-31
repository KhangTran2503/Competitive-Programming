#include <bits/stdc++.h>
using namespace std;
int n, k, m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    int miss = m*n;
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        miss -= x;
    }
    if (miss <= k) cout << max(miss,0);
    else cout << -1;
    return 0;
}