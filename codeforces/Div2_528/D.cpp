/*    I_LOVE_THUY_LINH   */
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector
#define fir first
#define sec second
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e5)+5
using namespace std;
int deg[N];
int n,s;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1) cnt++;

    db res = 2*db(s)/db(cnt);
    cout << fixed << setprecision(10) << res;
    return 0;
}
