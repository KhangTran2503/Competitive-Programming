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
#define N 2*int(1e5)+5
using namespace std;
vi a[N];
int n;

int checknext(int u,int v){
    for (int x : a[u])
        if (x == v) return u;
    return v;
}


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int u,v;
        cin >> u >> v;
        a[i].pb(u);
        a[i].pb(v);
    }
    if (n == 3){
        cout << "1 2 3";
        return 0;
    }
    vi ans;
    ans.pb(1);
    while (ans.size() < n){
        int last = ans.back();
        int next = checknext(a[last][0],a[last][1]);
        ans.pb(next);
    }

    for (int x: ans) cout << x <<' ';
    //cout << res;
    return 0;
}
