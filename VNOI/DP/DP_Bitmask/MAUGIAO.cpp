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
ll dpmax[1 << 20], dpway[1 << 20];
ll a[20][20];
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> a[i][j];

    dpmax[0] = 0;
    dpway[0] = 1;
    for (int mask = 1; mask < (1<<n); mask++){
        int j = bitcount(mask) - 1;
        for (int i = 0; i < n; i++)
            if (getbit(mask,i)){
                int prestate = offbit(mask,i);
                if (dpmax[mask] < dpmax[prestate] + a[i][j]){
                    dpmax[mask] = dpmax[prestate] + a[i][j];
                    dpway[mask] = dpway[prestate];
                }
                else if (dpmax[mask] == dpmax[prestate] + a[i][j]) dpway[mask] += dpway[prestate];
            }
    }
    cout << dpmax[(1<<n) - 1] << ' ' << dpway[(1<<n)-1];
    return 0;
}
