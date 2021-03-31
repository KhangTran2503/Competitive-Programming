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

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int &ai: a) cin >> ai;
    vi cnt(2*k + 1);
    vi presum(2*k + 2);
    for (int i = 0; i < n/2; i++) {
        cnt[a[i] + a[n - i - 1]]++;
        int l = min(a[i],a[n - i - 1]) + 1;
        int r = max(a[i],a[n - i - 1]) + k;
        presum[l]++;
        presum[r + 1]--;
    }
    int ans = INF;
    for (int x = 2; x <= 2*k; x++){
        presum[x] += presum[x - 1];
        ans = min(ans,presum[x] - cnt[x] + (n/2 - presum[x])*2);
    }
    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}