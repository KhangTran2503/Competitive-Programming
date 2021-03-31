#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;

int getbit(int s,int k){
    return (s >> k) & 1;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
    vector<vector<ii>> g(n);
    for (int i = 0; i < n; i++){
        int Ai;
        cin >> Ai;
        for (int j = 0; j < Ai; j++){
            int x, y;
            cin >> x >> y;
            x--;
            g[i].emplace_back(ii(x,y));
        }
    }


    int maxmask = (1 << n);
    int ans = 0;
    for (int msk = 0; msk < maxmask; msk++){
        int cnt = 0;
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (getbit(msk,i)){
                cnt++;
                for (auto v: g[i])
                    if ((getbit(msk,v.first)) ^ v.second) ok = false;
            }        
        if (ok) ans = max(ans,cnt);            
    }

    cout << ans;
    return 0;
}