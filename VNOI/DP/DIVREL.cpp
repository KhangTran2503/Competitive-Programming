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
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int T[205];
int dp[205] = {0};
int ans, ans1, n;

bool check(int u,int pos,vi a){
    while (pos != -1){
        if (u % a[pos] == 0) return false;
        pos = T[pos];
    }
    return true;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    ms(T,-1);
    ans = 0;
    for (int i = 0; i < n; i++){
        int Maxx = 0, idmin = -1;
        for (int j = 0; j < i; j++)
            if (check(a[i],j,a)){
                if (Maxx < dp[j] + 1){
                    Maxx = dp[j] + 1;
                    idmin = j;
                }
            }
        T[i] = idmin;
        dp[i] = Maxx;
        if (dp[i] > ans){
            ans = dp[i];
            ans1 = i;
        }
    }

    cout << ans << '\n';
    vi as;
    while (ans1 != -1){
        as.pb(a[ans1]);
        ans1 = T[ans1];
    }
    for (int i = sz(as) - 1; i >= 0; i--) cout << as[i] << ' ';

    return 0;
}
