/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
ll n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n ;
    ll begin = max(1LL,n-100);
    ll res = 0;
    for (ll i = begin; i <= n; i++)
        for (ll j = i; j <= n; j++)
            for (ll k = j; k <= n; k++)
                res = max(res,lcm(i,lcm(j,k)));
    cout << res;
    return 0;
}
