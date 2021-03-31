#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e7) + 1;
const int INF = 2*int(1e9);
vector<int> pmin(Maxn,Maxn + 1), pmax(Maxn,0);
int X, A, B, C;


void init(){
    for (int i = 2; i < Maxn/2; ++i)
        if (pmax[i] == 0){
            for (int j = i + i; j < Maxn; j += i){
                pmax[j] = max(pmax[j],i);
                pmin[j] = min(pmin[j],i);
            }
        }
}

void solve(){
   cin >> X;
   cin >> A >> B >> C;
   int ans = INF;
   if (pmax[X] == 0) ans = C + X;
   else if (pmax[X]*pmin[X] == X){
        ans = min(ans,C + X);
        ans = min(ans,A + pmin[X]);
   }
   else{
        ans = min(ans,C + X);
        ans = min(ans,A + X/pmax[X]);
        ans = min(ans,B + pmin[X]);
   }
   cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
