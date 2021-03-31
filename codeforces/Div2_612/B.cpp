#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <string,int> cnt;
int n, k;
char ch[] = {'S','E','T'};
map <char,int> num;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    num['S'] = 0;
    num['E'] = 1;
    num['T'] = 2;
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
        cnt[s[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++){
            string t;
            for (int h = 0; h < k; h++) 
                if (s[i][h] == s[j][h]) t.push_back(s[i][h]);
                else t.push_back(ch[3 - num[s[i][h]] - num[s[j][h]]]);
            ans += (ll)cnt[t];
            if (t == s[i] && t == s[j]) ans -= 2;
        }
    cout << ans/3;
    return 0;
}