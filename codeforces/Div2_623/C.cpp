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
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> a(2*n);
    set<int> s;
    vector<ii> p;
    for (int i = 1; i <= 2*n; i++) s.insert(i);
    for (int i = 1; i <= n; i++){ 
        cin >> b[i - 1];
        s.erase(b[i - 1]);
        a[2*i - 2] = b[i - 1];
        p.eb(b[i - 1],2*i - 2);
    }
    //sort(all(p));
    for (int i = 0; i < p.size(); i++){
        int u = p[i].fir;
        auto it = s.upper_bound(u);
        if (it == s.end()){
            cout << -1 << '\n';
            return;
        }
        a[p[i].second + 1] = *it;
        s.erase(it);
    }
    for (int i = 0; i < 2*n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}