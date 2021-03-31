#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s;
    vector<int> ans;
    for (int i = 1; i < s.size() - 1; i++)
        if (s[i] != s[i - 1]){
            s[i] = s[i - 1];
            ans.push_back(i);
            if (s[i + 1] == 'W') s[i + 1] = 'B';
            else s[i + 1] = 'W';
        }    
 
    for (int i = s.size() - 2; i >= 1; i--)
        if (s[i] != s[i + 1]){
            s[i] = s[i  + 1];
            ans.push_back(i - 1);
            if (s[i - 1] == 'W') s[i - 1] = 'B';
            else s[i - 1] = 'W';
        }    
 
    for (int i = 1; i < s.size() - 1; i++)
        if (s[i] != s[i - 1]){
            s[i] = s[i - 1];
            ans.push_back(i);
            if (s[i + 1] == 'W') s[i + 1] = 'B';
            else s[i + 1] = 'W';
        }    
    //cout << s << '\n';    
    bool ok = true;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1]) ok = false;
 
    if (ok){
        cout << int(ans.size()) << '\n';
        for (int x: ans) cout << x + 1 << ' ';
    }       
    else cout << -1;
    return 0;
}