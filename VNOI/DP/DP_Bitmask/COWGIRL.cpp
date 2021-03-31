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
using namespace std;
const db Pi = acos(-1);
ll way[30][1 << 5];
int n ,m , T;

bool check(int mask1,int mask2,int n){
    for (int i = 0; i < n - 1; i++){
        int tmp = 0;
        if (getbit(mask1,i)) tmp ++;
        if (getbit(mask1,i+1)) tmp ++;
        if (getbit(mask2,i)) tmp ++;
        if (getbit(mask2,i+1)) tmp ++;
        //cout << tmp << '\n';
        if (tmp == 4 || tmp == 0) return false;
    }
    return true;
}

ll solve(int n,int m){
    if (n == 1) return (ll)(1 << m);
    ms(way,0);
    for (int mask = 0; mask < (1 << n); mask++) way[0][mask] = 1;

    for (int i = 1; i < m; i++)
        for (int mask = 0; mask < (1 << n); mask++){
            for (int mask2 = 0; mask2 < (1 << n); mask2 ++)
                if (check(mask,mask2,n)) way[i][mask] += way[i-1][mask2];
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) ans += way[m-1][mask];
    return ans;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n >> m;
        if (n > m) swap(n,m);
        cout << solve(n,m) << '\n';

    }
    return 0;
}
