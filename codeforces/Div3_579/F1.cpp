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
int n, r;

/// don't finish

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> r;
    vector<ii> project(n);
    for (ii &i: project) cin >> i.first >> i.second;

    vector<bool> visit(n);
    for (int i = 0; i < n; i++){
        int cur = -1;
        for (int j = 0; j < n; j++)
            if (!visit[j] && project[j].first <= r){
                if ((cur == -1) || (project[j].second >= project[cur].second)) cur = j;
            }
        if ((cur == -1) || (r + project[cur].second <= 0)){
            cout << "NO";
            return 0;
        }
        cout << cur << '\n';
        visit[cur] = true;
        r += project[cur].second;
    }
    cout << "YES";
    return 0;
}