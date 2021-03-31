#include <bits/stdc++.h>
using namespace std;
int q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        int R = 0, U = 0, L = 0, D = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R') R++;
            if (s[i] == 'L') L++;
            if (s[i] == 'U') U++;
            if (s[i] == 'D') D++;
        }

        int UD = min(U,D), LR = min(L,R);
        if (UD == 0) LR = min(LR,1);
        if (LR == 0) UD = min(UD,1);
        cout << 2*(UD + LR) << '\n';
        string ans = "";
        for (int i = 0; i < LR; i++) ans.push_back('R');
        for (int i = 0; i < UD; i++) ans.push_back('U');
        for (int i = 0; i < LR; i++) ans.push_back('L');
        for (int i = 0; i < UD; i++) ans.push_back('D');
        cout << ans << '\n';
    }   
    return 0;
}