#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 2*int(1e5) + 5;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> f(n);
    vector<int> ok(Maxn + 1,0);
    vector<int> pos;
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++){
        cin >> f[i];
        if (f[i] == 0){
            pos.push_back(i + 1);
        }
        else {
            ok[f[i]] = 1;
            ans[i + 1] = f[i];
        }    
    }

    vector<int> b;
    for (int i = 1; i <= Maxn; i++)
        if (!ok[i]) b.push_back(i);

    for (int i = 0; i < pos.size() - 1; i++)
        if (!(b[i] != pos[i] && b[i + 1] != pos[i + 1])) swap(b[i],b[i + 1]);
    
    for (int i = 0; i < pos.size(); i++) ans[pos[i]] = b[i];

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    
    return 0;
}