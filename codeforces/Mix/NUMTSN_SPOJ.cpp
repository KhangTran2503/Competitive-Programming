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
const ll Mod = (ll)(1e9) + 7;
const int maxlen = 17;
int t;
string s1, s2;
ll memo[50][2][2*maxlen + 1][2*maxlen + 1][2][2];

ll dp(int pos,bool nonzero,int diff1,int diff2,bool low,bool high){
    if (pos == s2.size()){
        if (nonzero && (diff1 == 0) && (diff2 == 0)) return 1;
        else return 0;
    }

    ll &ans = memo[pos][nonzero][diff1 + maxlen][diff2 + maxlen][low][high];
    if (ans != -1) return ans;

    ans = 0;
    for (int digit = 0; digit < 10; digit++){
        if (((digit >= s1[pos] - '0') || high) && ((digit <= s2[pos] - '0') || low)){
            bool newnonzero = nonzero;
            int newdiff1 = diff1;
            int newdiff2 = diff2;
            if (digit == 3){
                newnonzero = 1;
                newdiff1 --;
                newdiff2--;
                if (!(newdiff1 >= -17 && newdiff2 >= -17)) continue;
            }
            else if (digit == 6){
                newdiff1++;
                if (newdiff1 > 17) continue;
            }
            else if (digit == 9){
                newdiff2++;
                if (newdiff2 > 17) continue;
            }
            ans = (ans + dp(pos + 1,newnonzero,newdiff1,newdiff2,(digit < s2[pos] - '0') || low,(digit > s1[pos] - '0') || high) ) % Mod;
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        cin >> s1 >> s2;
        while (s1.size() < s2.size()) s1 = "0" + s1;
        memset(memo,-1,sizeof(memo));
        cout << dp(0,0,0,0,0,0) << '\n';
    }
    return 0;
}