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
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
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
const db Pi = acos(-1);
bool dp[N][2];
string s;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> s;
    int n = sz(s);
    for (int i = 0; i < n; i++){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        if (i > 0){
            if (s[i-1] == 'A' && s[i] == 'B') {
                if (dp[i-1][0]){
                    cout << "YES";
                    return 0;
                }
                dp[i+1][1] = 1;
            }
            if (s[i-1] == 'B' && s[i] == 'A') {
                if (dp[i-1][1]){
                    cout << "YES";
                    return 0;
                }
                dp[i+1][0] = 1;
            }
        }
    }
    cout << "NO";
    return 0;
}
