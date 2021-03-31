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
int k;
string s, t, ans;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> k;
    cin >> s;
    cin >> t;
    int rem = 0;
    vector<int> a(k);
    /// a[i] la a[i] * 26^(i-1)
    /// bieu dien so s = s[0]*26^0 + s[1]*26^1 + ... + s[n]* 26^n
    /// bieu dien so t = t[0]* 26^0 + t[1] * 26 ^ 1 + .... + t[n] * 26^n
    /// Cong 2 so t va s theo he co so 26
    /// chia 2 theo quy tac giong chia 2 he co so 10
    for (int i = k - 1 ; i >= 0; i--){
        int id1 = s[i] - 'a';
        int id2 = t[i] - 'a';
        a[i] = (id1 + id2 + rem) % 26;
        rem  = (id1 + id2 + rem) / 26;
    }

    for (int i = 0; i < k; i++){
        int id3 = (rem * 26 + a[i]) / 2;
        rem = a[i] % 2;
        ans.pb(char('a' + id3));
    }
    cout << ans;
    return 0;
}
