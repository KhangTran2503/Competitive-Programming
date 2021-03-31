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
vi g[N];
int c[N], visit[N];
int n,m,k;
ll ans = 0;

void dfs(int u,int& num){
    visit[u] = 1;
    num ++;
    for (int v: g[u])
        if (!visit[v]) dfs(v,num);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ms(visit,0);
    int Maxnum = 0;
    int Numcom = 0;
    for (int i = 1; i <= k; i++)
        if (visit[c[i]]) {
            cout << 0;
            return 0;
        }
        else {
            int num = 0 ;
            dfs(c[i],num);
            Maxnum = max(Maxnum,num); // tim dinh trong tap k co so dinh lon nhat
            ans += ((ll)num*(ll)(num-1))/2; // tang so luong canh voi moi tap toi da
        }

    for (int i = 1; i <= n; i++)
        if (!visit[i]) {
            int num = 0 ;
            dfs(i,num);
            //cout << num << ' ' << edge << '\n';
            Numcom += num;
        }
    ans -= (ll)Maxnum*(ll)(Maxnum-1)/2;
    Numcom += Maxnum;
    //cout << ans <<'\n';
    ans += ((ll)(Numcom)*(ll)(Numcom-1)/2) - m; /// ghep dinh lon nhat vs so dinh con lai
    cout << ans;
    return 0;
}
