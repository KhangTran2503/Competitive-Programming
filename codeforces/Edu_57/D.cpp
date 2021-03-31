/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e17)
#define N int(1e5)+5
using namespace std;
char hard[] = {'h','a','r','d'};
ll dp[N][5];
string s;
int n;
int a[N];

ll calc(int i,int j){
    if (j == 4) return oo;
    if (i == n+1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    ll res = 0;
    if (s[i] == hard[j]){
        res = min(calc(i+1,j+1), calc(i+1,j) + a[i]);
    }
    else res = calc(i+1,j);
    return dp[i][j] = res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s; s = ' '+s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ms(dp,-1);
    cout << calc(1,0);
    return 0;
}
