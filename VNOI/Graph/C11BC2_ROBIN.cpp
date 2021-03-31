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
#define N int(1e4)+5
using namespace std;
int par1[N];
int n, m;

int anc1(int u){ return (par1[u] == u) ? u : (par1[u] = anc1(par1[u]));}
void join1(int u,int v){ par1[anc1(u)] = anc1(v);}


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par1[i] = i;
    for (int i = 2; i <= n; i++){
        int u,k;
        cin >> u >> k;
        if (k == 1){
            if (anc1(i) != anc1(u)) join1(i,u);
        }
    }




    for (int i = 1 ; i <= m; i++){
        int x,y;
        cin >> x >> y;
        int u = anc1(x), v = anc1(y);
        if (u == v) cout << "NO" << '\n';
        else cout << "YES"<< '\n';
    }
    return 0;
}
