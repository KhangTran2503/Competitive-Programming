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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int odd1 = -1, odd2 = -1;
        int i = s.size() - 1;
        while (i >= 0){
            if ((s[i] - '0') % 2 == 1){
                odd2 = s[i];
                i--;
                break;
            }
            i--;
        }
        while (i >= 0){
            if ((s[i] - '0') % 2 == 1){
                odd1 = s[i];
                i--;
                break;
            }
            i--;
        }
        if (odd1 != -1 && odd2 != -1) cout << char(odd1) << char(odd2) << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}