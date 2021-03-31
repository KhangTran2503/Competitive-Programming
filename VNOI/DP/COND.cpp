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
int C[11][11] = {0};

void init(){
    for (int i = 0; i <= 10; i++) C[0][i] = 1;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= i; j++) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    }
}
// dp[i][j] la xet tap co i phan tu va chia thanh j phan 
// dp[i][j] = sum[k: 1 - i] (dp[i - k][j - 1]*C[k][n]) 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    while (1){
        int n;
        cin >> n;
        if (n == -1) break;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1));
        dp[0][0] = 1;
       for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) 
                for (int k = 1; k <= i; k++) dp[i][j] += dp[i - k][j - 1]*C[k][i];
        int ans = 0;
        for (int k = 1; k <= n; k++) ans += dp[n][k]; 

        cout << ans << '\n';
    }
    return 0;
}