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
    // f(x) number bits 1 of x
    // => f(x1^x2) = f(x1) + f(x2) - 2f(x1 & x2) // inclusion-exclusion
    // => so ans_odd = sum (f(P ^ xi) % 2) = sum(f(P) % 2 + f(xi) % 2) , because 2f(P & x2) % 2 = 0
    int T;
    cin >> T;
    while (T--){
        int n, q;
        cin >> n >> q;
        int sumfxi = 0;
        for (int i = 0; i < n; i++){
            ll x;
            cin >> x;
            sumfxi = sumfxi + (bitcount(x) % 2);
        }
        while (q--){
            ll P;
            cin >> P;
            int odd = sumfxi;
            int even = n - odd;
            if (bitcount(P) & 1) swap(odd,even);
            cout << even << ' ' << odd << '\n'; 
        } 
    }
    return 0;
}