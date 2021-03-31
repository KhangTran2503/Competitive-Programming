#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
int k;
ll ans = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> s;
    vector<int> visit(26,0);
    for (int i = 0; i < k; i++){
        char x;
        cin >> x;
        visit[x - 'a'] = 1;
    }

    ll cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (i == s.size() - 1 || !visit[s[i] - 'a']){
            if (visit[s[i] - 'a']) cnt++;
            ans += cnt*(cnt + 1)/2;
            cnt = 0;
        }
        else cnt++;
    }
    cout << ans;
    return 0;
}
