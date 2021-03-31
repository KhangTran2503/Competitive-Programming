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
    int a, b , c;
    cin >> a >> b >> c;

    vector<vector<int>> dp(20001,vector<int> (3,INF));
    for (int i = 1; i <= 20000; i++){
        dp[i][0] = abs(i - a);
        for (int j = i ; j <= 20000; j+= i){
            dp[j][1] = min(dp[j][1],dp[i][0] + abs(j - b));
            dp[j][2] = min(dp[j][2],dp[i][1] + abs(j - c));
        }
    }
    int C = 20000;
    for (int i = 1; i <= 20000; i++)
        if (dp[i][2] < dp[C][2]) C = i;
    
    int B;
    for (int i = 1; i <= 20000; i++)
        if ((C % i  == 0) && dp[i][1] + abs(C - c)== dp[C][2]){
            B = i;
            break;
        }
    int A;    
    for (int i = 1; i <= 20000; i++)
        if ((B % i  == 0) && dp[i][0] + abs(B - b)== dp[B][1]){
            A = i;
            break;
        }
    cout << dp[C][2] << '\n';
    cout << A << ' ' << B << ' ' << C << '\n';
    

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}