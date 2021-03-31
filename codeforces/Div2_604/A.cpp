#include <bits/stdc++.h>
using namespace std;
int T;
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--){
        cin >> s;
        char pre , next;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?'){
                if (i == 0) pre = 'x';
                else pre = s[i - 1];
                if (i == s.size() - 1) next = 'x';
                else next = s[i + 1];

                for (char x : {'a','b','c'})
                    if (x != next && x != pre){
                        s[i] = x;
                        break;
                    }
            }

        bool ok = true;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == s[i - 1]){
                ok = false;
                break;
            }    
        if (ok) cout << s << '\n';
        else cout << -1 << '\n';    
    }
    return 0;
}