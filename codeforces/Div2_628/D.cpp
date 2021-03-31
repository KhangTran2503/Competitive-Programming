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
// xorarray % 2 == sumarray % 2

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll u, v;
    cin >> u >> v;
    if (u == v){
        if (u == 0) cout << 0;
        else cout << 1 << '\n' << u;
        return 0;
    }
    if (u < v){
        if ((v - u) % 2 == 0){
            ll ans1 = u;
            ll ans2 = (v - u)/2LL;
            ll ans3 = ans2;
            ll ans = ans1 ^ ans2;
            if (ans == ans1 + ans2){
                cout << 2 << '\n';
                cout << ans1 + ans2 << ' ' << ans2;
            } 
            else{
                cout << 3 << '\n';
                cout << ans1 << ' ' << ans2 << ' ' << ans3;
            }
        }
        else cout << -1;
    }
    else cout << -1;
    return 0;
}