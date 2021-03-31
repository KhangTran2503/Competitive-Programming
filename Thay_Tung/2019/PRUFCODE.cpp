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
vi pruf_code;
int n;

void prufer_decode_linear(vi pruf_code){
    n += 1;
    vi deg(n,1);
    for (int i = 0; i < n - 2; i++) ++deg[pruf_code[i]];
    int ptr = 0;
    while (ptr < n && deg[ptr] != 1) ptr ++;
    int leaf = ptr;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 2; i++){
        int v = pruf_code[i];
        g[leaf].pb(v);
        g[v].pb(leaf);
        --deg[leaf];
        if (--deg[v] == 1 && v < ptr) leaf = v;
        else {
            ptr ++;
            while (ptr < n && deg[ptr] != 1) ++ptr;
            leaf = ptr;
        }
    }
    for (int v = 0; v < n - 1; ++ v)
        if (deg[v] == 1){
            g[v].pb(n - 1);
            g[n - 1].pb(v);
        }

    for (int u = 0; u < n - 1; u++){
        cout << u + 1 <<": ";
        for (int v: g[u]) cout << v + 1 << ' ';
        cout << '\n';
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    pruf_code.resize(n);
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        x --;
        pruf_code[i] = x;
    }
    prufer_decode_linear(pruf_code);


    return 0;
}
