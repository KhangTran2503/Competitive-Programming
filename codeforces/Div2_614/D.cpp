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
const ll Limit = (ll)(1e16);
ll X0, Y0, ax, ay, bx, by, xs, ys, t;

ll dis(pair<ll,ll> u, pair<ll,ll> v){
    return abs(u.fir - v.fir) + abs(u.sec - v.sec);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<pair<ll,ll>> p;
    cin >> X0 >> Y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    p.emplace_back(make_pair(X0,Y0));
    while (p.back().fir <= Limit && p.back().sec <= Limit){
        ll u = p.back().fir;
        ll v = p.back().sec;
        p.emplace_back(make_pair(ax*u + bx,ay*v + by));
    }

    int ans = 0;
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < p.size(); j++)
            if (dis(make_pair(xs,ys),p[i]) + dis(p[i],p[j]) <= t) 
                ans = max(ans,abs(i - j) + 1);
    cout << ans;

    return 0;
}