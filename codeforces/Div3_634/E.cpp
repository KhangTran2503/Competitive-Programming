/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<ii>
#define matrix vector<vector<ll>>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
using namespace std;
const int INF = int(1e9);
const int Maxval = 201;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> cnt_lef(Maxval,vi (n + 2));
    vi a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];


    vector<vi> pos(Maxval);
    for (int i = 1; i < Maxval; i++){
        for (int j = 1; j <= n; j++){ 
            cnt_lef[i][j] = cnt_lef[i][j - 1] + (i == a[j]);
            if (i == a[j]) pos[i].eb(j);
        }
    }

    int ans = 0;
    for (int i = 1; i < Maxval; i++){
        int len = cnt_lef[i][n];
        for (int sublen = 1; 2*sublen <= len; sublen++){
            int l = pos[i][sublen - 1] + 1;
            int r = pos[i][len - sublen] - 1;
            int tmp = 0;
            if (l <= r){
                for (int j = 1; j < Maxval; j++)
                    if (i != j) tmp = max(tmp,cnt_lef[j][r] - cnt_lef[j][l - 1]);
            }
            ans = max(ans,sublen*2 + tmp);
        } 
        ans = max(ans,cnt_lef[i][n]);
        
    }
    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}