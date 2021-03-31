#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int nn = 2*n;
        vector<int> sum(nn + 2,0);
        for (int i = 1; i <= nn; i++){
            int x;
            cin >> x;
            if (x == 1) sum[i] = sum[i - 1] + 1;
            else sum[i] = sum[i - 1] - 1;
        }
        sum[nn + 1] = sum[nn];
        vector<pair<int,int>> sumpart;
        for (int i = n; i <= nn; i++)
            sumpart.push_back(make_pair(sum[i],i));
        sort(sumpart.begin(),sumpart.end());

        int ans = nn;
        for (int i = 0; i <= n; i++){
            auto it = lower_bound(sumpart.begin(),sumpart.end(),make_pair(sum[i] + sum[nn],-1));
            if (it == sumpart.end()) continue;
            if (it->first != (sum[i] + sum[nn])) continue;
            ans = min(ans,(it->second) - i);
        }       
        cout << ans << '\n';
    }
    return 0;
}