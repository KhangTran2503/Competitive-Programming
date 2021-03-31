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
const ll lim = 998244353;
ll n;
ll ang;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> ang;
        ang*= 2;
        ll lc = lcm(ang,360LL);
        ll n = lc/ang;
        ll l = 1, r = (lim/l)+1;
        //cout << l << ' ' << r << '\n';
        ll res = -1;
        while (l <= r){
            ll mid = (l+r)>>1;
            if ((ang*mid*n)/(ll)360 < mid*n-1){
                res = mid*n;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout << res << '\n';

    }

    return 0;
}
