#include <bits/stdc++.h>
using namespace std;
int n, l, k;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> k;
    vector<char> s(n*l);
    for (int i = 0; i < n*l; i++) cin >> s[i];
    sort(s.begin(),s.end());
    vector<bool> used(n*l,0);
    vector<string> ans;
    string t = "";
    for (int i = k - 1; i < k + l - 1; i++) {
        t.push_back(s[i]);
        used[i] = 1;
    }

    ans.push_back(t);
    int j  = k + l - 1;
    for (int i = 0; i < n*l; i++){
        if (used[i]) continue;
        string t = "";
        t.push_back(s[i]);
        used[i] = 1;
        int cnt = 0;
        j = max(j,i + 1);
        while (cnt < l - 1){
            t.push_back(s[j]);
            used[j] = 1;
            j++;
            cnt++;
        }
        ans.push_back(t);
    }    
    sort(ans.begin(),ans.end());
    for (string x: ans) cout << x << '\n';

    return 0;
}