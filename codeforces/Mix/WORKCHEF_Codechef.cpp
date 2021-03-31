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
const int Lcm = 2520;
int K;
int q;
vector<int> digit;
ll memo[20][2][2520][(1 << 9) + 1];




ll dp(int pos,bool low,int mask,int remain){
    if (pos == digit.size()){
        int cnt = 0;
        for (int d = 1; d < 10; d++)
            if (getbit(mask,d - 1)){
                if (remain % d == 0) cnt++;
            }
        return (ll)(cnt >= K);
    }

    ll &ans = memo[pos][low][mask][remain];
    if (ans != -1) return ans;
    ans = 0;
    for (int d = 0; d < 10; d++)
        if (low || d <= digit[pos]){
            int newmask = mask;
            if (d > 0) newmask |= (1 << (d - 1));
            ans += dp(pos + 1,low || d < digit[pos],newmask,(remain*10 + d) % Lcm);
        }
    return ans;

}


ll solve(ll x){
    digit.clear();
    if (x == 0) {
        digit.push_back(x);
    }
    while (x) {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(all(digit));
    memset(memo, -1, sizeof(memo)); 
    return dp(0,0,0,0);

}




int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--){
        ll L, R;
        cin >> L >> R >> K;
        ll ans = solve(R) - solve(L - 1LL);
        cout << ans << '\n';
    }
    
   //check();
    return 0;
}