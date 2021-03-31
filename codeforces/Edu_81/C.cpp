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
int T;

void Solve(){
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> charpos(26);
    for (int i = 0; i < s.size(); i++)
        charpos[s[i] - 'a'].eb(i);
        
    int ans = 1;
    int curpos = -1;
    for (int i = 0; i < t.size(); i++){
        vi &x = charpos[t[i] - 'a'];
        if (x.empty()){
            cout << -1 << '\n';
            return;
        } 

        int id = upper_bound(all(x),curpos) - x.begin();
        if (id == x.size()){
            ans++;
            id = upper_bound(all(x),-1) - x.begin();
        }
        curpos = x[id];
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) Solve();
    return 0;
}