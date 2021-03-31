/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
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
const int Maxn = int(1e5) + 5;
int a[2][Maxn] = {0};
int n, q;
int ans = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    
    while (q--){
        int x, y;
        cin >> x >> y;
        x--;
        
        if (a[x][y] == 0){
            for (int k = -1; k < 2; k++)
            if (y + k >= 1 && y + k <= n){
                ans += a[1 - x][y + k];
            }
        }
        else {
            for (int k = -1; k < 2; k++)
            if (y + k >= 1 && y + k <= n){
                ans -= a[1 - x][y + k];
            }
        }
        
        a[x][y] ^= 1;
        //cout << ans << '\n';
        if (ans == 0) cout << "YES\n";
        else cout << "NO\n";    
        

    }
    return 0;
}