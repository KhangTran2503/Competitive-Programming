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
const ll INF = (ll)(1e18) + 5;
const ll limit = (ll)(1e18) + 5;
int prime[] = {0,2,3,5,7,11,13,17,19,23,29};
vector<vector<ll>> pw(11);
int n;
ll memo[1005][11];
// dp(n,k) la xet k so prime dau tien sao cho co dung n uoc 
// dp(n,k) = min(dp(n,k - 1),dp(n/(a + 1),k - 1)*pk^a)
void init(){
    for (int i = 1; i <= 10; i++){
        pw[i].emplace_back(1);
        while (pw[i].back() < limit/prime[i])
            pw[i].emplace_back(pw[i].back()*(ll)prime[i]);
    }
}

ll dp(int n,int pos){
    if (n == 1) return 1LL;
    if (pos == 0) return INF;
    ll &ans = memo[n][pos];
    if (ans != -1) return ans;
    ans = dp(n,pos - 1);
    int h = pw[pos].size();
    for (int a = 1; a < h; a++)
        if (n % (a + 1) == 0){
            ll tmp = dp(n/(a + 1),pos - 1);
            if (tmp < limit/pw[pos][a]) ans = min(ans,tmp*pw[pos][a]);
        }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    init();
    memset(memo,-1,sizeof(memo));
    cout << dp(n,10);
    return 0;
}