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

// s is special node
// dis(u,s) = d , exit v != s such that dis(u,v) = d
//  if program return v => dis(v,s) < dis(u,s)

void solve(){
    int h;
    cin >> h;
    int leaf;
    cout << 2 << ' ' << 1 << ' ' << h << endl;
    cin >> leaf;
    for (int i = 0; i < h; i++){
        cout << 1 << ' ' << leaf << endl;
        int dis;
        cin >> dis;
        if (dis == 0){
            cout << 3 << ' ' << leaf << endl;
            break;
        }
        cout << 2 << ' ' << leaf << ' ' << dis << endl;
        cin >> leaf;
    } 
    cout << 3 << ' ' << leaf << endl;
    cin >> leaf;
}

int main(){
    //ios::sync_with_stdio(0), cin.tie(0); //cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();    
    return 0;
}