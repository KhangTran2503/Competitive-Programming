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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m , p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % p != 0){
            res += i;
            break;
        }
    for (int i = 0; i < m; i++)
        if (b[i] % p != 0){
            res += i;
            break;
        }
    cout << res;
    return 0;
}