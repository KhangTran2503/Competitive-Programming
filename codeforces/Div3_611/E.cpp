#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int n;
// sort tang dan dam bao day tang 
// QHD tren day tang
// dp[i][diff] la do dai min/max tai o i ma co a[i] + diff 
// dieu kien la a[i - 1] + diff(i - 1) <= a[i] + diff
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end());

    vector<vector<int>> dpmin(n + 1,vector<int> (3,INF));
    vector<vector<int>> dpmax(n + 1,vector<int> (3,0));

    for (int i = 0; i < 3; i++) dpmin[1][i] = dpmax[1][i] = 1;

    for (int i = 2; i <= n; i++)
        for (int diff1 = -1; diff1 < 2; diff1++)
            for (int diff2 = -1; diff2 < 2; diff2++)
                if (a[i - 1] + diff1 < a[i] + diff2){
                    dpmax[i][diff2 + 1] = max(dpmax[i][diff2 + 1],dpmax[i - 1][diff1 + 1] + 1);
                    dpmin[i][diff2 + 1] = min(dpmin[i][diff2 + 1],dpmin[i - 1][diff1 + 1] + 1);
                }
                else if (a[i - 1] + diff1 == a[i] + diff2){
                    dpmax[i][diff2 + 1] = max(dpmax[i][diff2 + 1],dpmax[i - 1][diff1 + 1]);
                    dpmin[i][diff2 + 1] = min(dpmin[i][diff2 + 1],dpmin[i - 1][diff1 + 1]);
                }

    int ansmin = min(min(dpmin[n][0],dpmin[n][1]),dpmin[n][2]);
    int ansmax = max(max(dpmax[n][0],dpmax[n][1]),dpmax[n][2]);
    cout << ansmin << ' ' << ansmax << '\n';
    return 0;
}