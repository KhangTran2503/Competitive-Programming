#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);
        int pos0 = -1;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            if (a[i] == 0) pos0 =  i;
        }
        int lef = pos0;
        int rig = pos0;
        int maxnum = 0;
        ans[0] = 1;
        for (int i = 1; i < n; i++){
            if (lef > 0 && rig < n - 1){
                if (a[lef - 1] < a[rig + 1]) lef--;
                else rig++;
                maxnum = max(maxnum,a[lef]);
                maxnum = max(maxnum,a[rig]);
                ans[i] = (maxnum == rig - lef); 
            }
            else if (lef > 0){
                lef--;
                maxnum = max(maxnum,a[lef]);
                ans[i] = (maxnum == rig - lef);
            }
            else {
                rig++;
                maxnum = max(maxnum,a[rig]);
                ans[i] = (maxnum == rig - lef);
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i];
        cout << '\n';

    }
    return 0;
}
