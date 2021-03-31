#include <bits/stdc++.h>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<int> AC(n + 1);
    vector<int> WA(n + 1);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < m; i++){
        int x;
        string s;
        cin >> x >> s;
        if (AC[x] == 1) continue;
        if (s == "AC"){
            AC[x] = 1;
            ans1++;
            ans2 += WA[x];
        }
        else WA[x]++;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}