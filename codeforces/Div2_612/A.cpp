#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        s.push_back('A');
        int ans = 0;
        int pre = -1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'A'){
                if (pre != -1) ans = max(ans,i - pre -1);
                pre = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}