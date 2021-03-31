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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> dx(n + 1);
        vector<int> dy(n + 1);
        for (int i = 1; i <= n; i++){
            dx[i] = dx[i - 1];
            dy[i] = dy[i - 1];
            char x;
            cin >> x;
            if (x == 'R') dx[i]++;
            if (x == 'L') dx[i]--;
            if (x == 'U') dy[i]++;
            if (x == 'D') dy[i]--;
        }
        
        map<pair<int,int>,int> pos;
        pos[make_pair(dx[0],dy[0])] = 0;
        int ans = n + 1;
        int lans, rans;
        for (int i = 1; i <= n; i++){
            pair<int,int> d = make_pair(dx[i],dy[i]);
            if (pos.find(d) == pos.end()) pos[d] = i;
            else {
                int x = pos[d];
                if (ans > i - x){
                    ans = i - x;
                    lans = x + 1;
                    rans = i;
                }
                pos[d] = i;
            }
        }
        if (ans == n + 1) cout << -1 << '\n';
        else cout << lans << ' ' << rans << '\n';
        
    }
    return 0;
}