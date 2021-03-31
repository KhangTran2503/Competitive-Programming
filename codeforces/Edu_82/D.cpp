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
const int INF = int(1e9);

void solve(){
    int m;
    ll n;
    cin >> n >> m;
    ll sum = 0;
    vector<int> cnt(64);
    for (int i = 0; i < m; i++){
        ll x;
        cin >> x;
        sum += x;
        cnt[__builtin_ctz(x)]++;
    }

    if (sum < n){
        cout << -1 << '\n';
        return;
    }
    
    int ans = 0;
    for (int i = 0; i < 63; i++){
        if (getbit(n,i)){
            if (!cnt[i]){
                int j = i + 1;
                while (j < 64 && cnt[j] == 0) j++;
                for (int k = j - 1; k >= i; k--){
                    cnt[k + 1]--;
                    cnt[k] += 2;
                    ans++;
                }
            }
            cnt[i]--;
            //cnt[i + 1] += (cnt[i]/2);
        }
        cnt[i + 1] += (cnt[i]/2);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}