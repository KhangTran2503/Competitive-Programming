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
#define N int(1e5)+5
using namespace std;
int n, m, deg[N];
int cnt , cnt1;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    cnt = 0;
    for (int i = 1; i <=n; i++)
        if (deg[i] == 2) cnt++;
    if (cnt == n) {
        cout << "ring topology";
        return 0;
    }

    cnt = 0, cnt1 = 0;
    for (int i = 1 ; i <= n; i++){
        if (deg[i] == 2) cnt1++;
        if (deg[i] == 1) cnt++;
    }

    if (cnt == 2 && cnt1 == n-2){
        cout << "bus topology";
        return 0;
    }

    cnt = 0, cnt1 = 0;
    for (int i = 1 ; i <= n; i++){
        if (deg[i] == 1) cnt++;
        if (deg[i] == n-1) cnt1++;
    }
    if (cnt == n-1 && cnt1 == 1){
        cout << "star topology";
        return 0;
    }
    cout << "unknown topology";
    return 0;
}
