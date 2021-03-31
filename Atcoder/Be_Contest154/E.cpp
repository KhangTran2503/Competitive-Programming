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
ll memo[100][2][4];
int k;
string s;

ll dp(int pos,bool low,int cnt){
    if (pos == s.size()) return (cnt == k);
    ll &ans = memo[pos][low][cnt];
    if (ans != -1) return ans;
    ans = 0;
    for (int dg = 0; dg <= 9; dg++)
        if (low || (dg <= s[pos] - '0')){
            int newcnt = cnt + (dg != 0);
            if (newcnt <= k) ans += dp(pos + 1,low || (dg < s[pos] - '0'),newcnt);
        }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> k;
    memset(memo,-1,sizeof(memo));
    cout << dp(0,0,0);
    return 0;
}