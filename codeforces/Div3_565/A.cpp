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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        ll x;
        ll ans = 0;
        cin >> x;
        while (x != 1){
            bool ok = true;
            if (x % 2 == 0){
                x /=2;
                ans ++;
                continue;
            }
            if (x % 3 == 0){
                x = 2*(x/3);
                ans ++;
                continue;
            }
            if (x % 5 == 0){
                x = 4*(x/5);
                ans ++;
                continue;
            }
            if (ok){
                ans = -1;
                break;
            }

        }
        cout << ans << '\n';
    }

    return 0;
}
