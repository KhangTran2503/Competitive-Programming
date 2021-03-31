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
vector<set<int>> g(26);
vector<int> d(26);
vector<int> deg(26);

bool bfs(int id,string &x){
    x = "";
    queue<int> q;
    q.push(id);
    vector<int> par(26,0);
    d[id] = 1;
    par[id] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (g[u].size() >= 3) return false;
        x.push_back(char(u + int('a')));
        for (int v: g[u])
                if (v != par[u]){
                    if (d[v]) return false;
                    q.push(v);
                    par[v] = u;
                    d[v] = 1;
                }
            
    }
    return true;
}

void solve(){
    string s;
    cin >> s;
    d.assign(26,0);

    for (int i = 1; i < s.size(); i++){
        g[s[i] - 'a'].insert(s[i - 1] - 'a');
        g[s[i - 1] - 'a'].insert(s[i] - 'a');
    }

    string ans = "";
    bool ok = true;
    for (int i = 0; i < 26; i++)
        if (!d[i]){
            if (g[i].empty()) ans.push_back(char(int('a') + i));
            else if (g[i].size() == 1){
                string tmp = "";
                if (bfs(i,tmp)) ans += tmp;
                else {
                break;
                } 
            }   
        }    

    //cout << ans << '\n';
    if (ans.size() == 26){
        cout << "YES\n";
        cout << ans << '\n';
    }
    else cout << "NO\n";
    for (int i = 0; i < 26; i++) g[i].clear();


}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}