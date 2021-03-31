#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        string s;
        string h;
        cin >> s;
        sort(s.begin(),s.end());
        cin >> h;
        int n = s.size();
        if (n > h.size()){
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        for (int i = 0; i <= h.size() - n; i++){
            string x = h.substr(i,n);
            sort(x.begin(),x.end());
            if (x == s) ok = true;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return  0;
}