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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int n, k;
string s;
map<string,int> d;

string cut(string t,int pos){
    string r = "";
    for (int i = 0; i < pos; i++) r.push_back(t[i]);
    for (int i = pos + 1; i < t.size(); i++) r.push_back(t[i]);
    return r;
}
int bfs(){
    int ans = 0;
    queue<string> q;
    d[s] = 1;
    q.push(s);
    int cnt = 0;
    while (!q.empty()){
        string u = q.front();
        q.pop();
        ans += (d[u] - 1);
        cnt ++;
        if (cnt == k) return ans;
        for (int i = 0; i < u.size(); i++){
            string v = cut(u,i);
            if (!d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }

    }
    return -1;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    cout << bfs();
    return 0;
}
