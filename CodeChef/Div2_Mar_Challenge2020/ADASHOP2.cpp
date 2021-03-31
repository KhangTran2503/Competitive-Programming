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
ii fake[19] = {{2,2},{3,1},{1,3},{2,4},{1,5},{5,1},{6,2},{7,1},{1,7},{2,8},{8,2},{7,3},{8,4},{4,8},{5,7},{6,8},{8,6},{7,7},{8,8}};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int r, c;
        cin >> r >> c;
        int len = 19;
        if (r == c){
            if (r != 1){
                cout << len  + 1 << '\n';
                cout << r << ' ' << c << '\n';
                for (ii x: fake) cout << x.fir << ' ' << x.sec << '\n';
            }
            else {
                cout << len << '\n';
                for (ii x: fake) cout << x.fir << ' ' << x.sec << '\n';
            }
        }
        else {
                cout << len + 2 << '\n';
                cout << (r + c)/2 << ' ' << (r + c)/2 << '\n';
                cout << 1 << ' ' << 1 << '\n';
                for (ii x: fake) cout << x.fir << ' ' << x.sec << '\n';
        }
    }
    return 0;
}