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
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
int n,m,q;
int qe[N], out[N], par[N];
int ans ;

int arc(int u){
    if (u == par[u]) return u;
    else return par[u] = arc(par[u]);
}

void join(int u,int v){
    int U = arc(u), V = arc(v);
    par[U] = V;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> q;
    vii edge(m);
    ms(out,0);
    for (int i = 0; i < m; i++){
        cin >> edge[i].fir >> edge[i].sec;
    }
    for (int i = 0; i < q; i++){
        cin >> qe[i];
        qe[i] --;
        out[qe[i]] = 1;
    }

    for (int i = 1; i <= n; i++) par[i] = i;
    ans = n;
    for (int i = 0; i < m; i++)
        if (!out[i]){
            if (arc(edge[i].fir) != arc(edge[i].sec)){
                ans--;
                join(edge[i].fir,edge[i].sec);
            }
        }

    vi res(q);
    for (int i = q-1; i >= 0; i--){
        int id = qe[i];
        //cout << id << '\n';
        res[i] = ans;
        if (arc(edge[id].fir) != arc(edge[id].sec)){
            ans --;
            join(edge[id].fir,edge[id].sec);
        }

    }
    for (int i = 0; i < q; i++) cout << res[i] << '\n';
    return 0;
}
