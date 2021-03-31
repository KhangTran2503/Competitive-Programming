/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
int H, W, K;
vector<vi> a;

int get(int u1, int v1,int u2,int v2){
    return a[u2][v2] - a[u1 - 1][v2] - a[u2][v1 - 1] + a[u1 - 1][v1 - 1];
}


int f(int c1,int c2,const vi& row){
    for (int i = 1; i < row.size(); i++){
        int r1 = row[i - 1] + 1;
        int r2 = row[i];
        int sum = get(r1,c1,r2,c2);
        if (sum > K) return false;
    }
    return true;
}

int calc(int msk){
    vi row;
    row.eb(0);
    int res = 0;
    for (int i = 0; i < H - 1; i++)
        if (getbit(msk,i)){ 
            res++;
            row.eb(i + 1);
        }
    row.eb(H);
   

    int lef = 1;
    int rig = 1;
    while (rig <= W){
        while (rig <= W  && f(lef,rig,row)) rig++;
        if (lef == rig) return INF;
        res++;
        lef = rig;
    }
    return res - 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> H >> W >> K;
    
    a.resize(H + 1,vi (W + 1));
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j){
            char x;
            cin >> x;
            a[i][j] = (x - '0') + a[i - 1][j] + a[i][j - 1]  - a[i - 1][j - 1];
        }
    
    int mask = (1 << (H - 1));
    int ans = INF;
    for (int msk = 0; msk < mask; msk++){
        ans = min(ans,calc(msk));
    }
    cout << ans << '\n';

    return 0;
}
