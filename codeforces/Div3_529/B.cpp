/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector
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
#define N int(1e5)+5
using namespace std;
multiset<int> s;
int a[N];
int n;


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <=n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    int res = int(1e9);
    for (int i = 1; i <= n; i++){
        s.erase(s.find(a[i]));
        //cout << *s.rbegin() << ' ' << *s.begin();
        res = min(res,(*s.rbegin())-(*s.begin()));
        s.insert(a[i]);
    }
    cout << res;
    return 0;
}
