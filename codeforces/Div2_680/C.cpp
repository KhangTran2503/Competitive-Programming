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
const int INF = int(1e9) + 5;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        int n, m;
        cin >> n >> m;
        vector<int> t(n + 1), l(n + 1), h(n + 1);
        for (int i = 1; i <= n; i++) cin >> t[i] >> l[i] >> h[i];
        ll minheat = m;
        ll maxheat = m;
        bool ok = true;
        for (int i = 1; i <= n; i++){
            minheat -= (ll)(t[i] - t[i - 1]);
            maxheat += (ll)(t[i] - t[i - 1]);
            minheat = max(minheat,(ll)l[i]);
            maxheat = min(maxheat,(ll)h[i]);
            if (minheat > maxheat){
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}