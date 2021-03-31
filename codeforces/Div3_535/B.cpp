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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e4)+5
using namespace std;
const db Pi = acos(-1);
vi d;
int n;
int cnt[N];
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d.pb(x);
        cnt[x] ++;
    }
    sort(all(d));
    cout << d[n-1] << ' ';
    set<int> s;
    for (int i = n-1; i >= 0; i--)
        if (d[n-1] % d[i] == 0 ){
            s.insert(d[i]);
        }
    for(auto x: s) cnt[x] --;
    int res = 1;
    for (auto x: d)
        if (cnt[x]){
            res = lcm(res,x);
            //cout << x << '\n';
        }
    cout << res;
    return 0;
}
