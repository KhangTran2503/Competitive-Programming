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

struct Point{
    int x, y;
};

int dis(Point u,Point v){
    return sqr(u.x - v.x) + sqr(u.y - v.y);
}


int cost(Point u,Point v,Point t){
    return dis(u,v) + dis(v,t) + dis(t,u);
}

Point start;
vector<Point> a;
vector<int> Trace;
int n;

void Print(int u){
    if (u == 0){
        cout << 0 << ' ';
        return;
    }
    else {
        Print(Trace[u]);
        int x = u ^ Trace[u];
        for (int i = 0; i < n; i++)
            if (getbit(x,i)) cout << i + 1 << ' ';
        cout << 0 << ' ';
    }
}



void DP(){
    vector<int> dp(1 << n);
    Trace.resize(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) dp[mask] = oo;
    for (int mask = 0; mask < (1 << n); mask++)
        if (dp[mask] < oo)
        {
            vi bit;
            for (int i = 0; i < n; i++)
                if (!getbit(mask,i)) bit.push_back(i);
            if (bit.empty()) continue;



            for (int i = 0; i < bit.size(); i++){
                int nextmask = turnbit(mask,bit[0]);
                nextmask = turnbit(nextmask,bit[i]);
                int dpmask =  dp[mask] + cost(start,a[bit[0]],a[bit[i]]);
                if (dpmask < dp[nextmask]){
                    dp[nextmask] = dpmask;
                    Trace[nextmask] = mask;
                }
            }
        }
    cout << dp[(1 << n) - 1] << '\n';
    Print((1 << n) - 1);

}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> start.x >> start.y;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    DP();

    return 0;
}
