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
int n, m , k;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    vi a(n + 1);
    vi b(m + 1);
    vi reca, recb;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int cnta = 0;
    for (int x: a)
        if (x == 0){
            if (cnta > 0) reca.eb(cnta);
            cnta = 0;
        }
        else cnta++;

    int cntb = 0;
    for (int x: b)
        if (x == 0){
            if (cntb > 0) recb.eb(cntb);
            cntb = 0;
        }
        else cntb++;
    
    if (reca.empty() || recb.empty()){
        cout << 0;
        return 0;
    }

    ll ans = 0;
    for (int i = 1; i*i <= k; i++)
        if (k % i == 0){
            int a = i;
            int b = k/i;
            ll tmp1 = 0, tmp2 = 0;
            for (int x: reca) tmp1 += max(0LL,(ll)(x - a + 1));
            for (int x: recb) tmp2 += max(0LL,(ll)(x - b + 1));
            ans += tmp1*tmp2;
            if (a == b) break;

            tmp1 = 0, tmp2 = 0;
            for (int x: reca) tmp1 += max(0LL,(ll)(x - b + 1));
            for (int x: recb) tmp2 += max(0LL,(ll)(x - a + 1));
            ans += tmp1*tmp2;
        }
    cout << ans;
    return 0;
}