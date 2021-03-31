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
int n, r1, c1, r2, c2;
vii land1, land2;
int visit[55][55];
int a[55][55];
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};

bool inside(int u, int v){
    return (u >= 1 && u <= n && v >= 1 && v <= n && (a[u][v] == 0) );
}

bool bfs1(){
    ms(visit,0);
    queue<ii> q;
    q.push(ii(r1,c1));
    land1.pb(ii(r1,c1));
    while (!q.empty()){
        int u = q.front().fir,
            v = q.front().sec;
        q.pop();
        for (int k = 0; k < 4; k++){
            int uu = u + dx[k],
                vv = v + dy[k];
            if (inside(uu,vv) && !visit[uu][vv]){
                if (uu == r2 && vv == c2) return true;
                visit[uu][vv] = 1;
                q.push(ii(uu,vv));
                land1.push_back(ii(uu,vv));
            }
        }
    }
    return false;
}

void bfs2(){
    ms(visit,0);
    queue<ii> q;
    q.push(ii(r2,c2));
    land2.pb(ii(r2,c2));
    while (!q.empty()){
        int u = q.front().fir,
            v = q.front().sec;
        q.pop();
        for (int k = 0; k < 4; k++){
            int uu = u + dx[k],
                vv = v + dy[k];
            if (inside(uu,vv) && !visit[uu][vv]){
                visit[uu][vv] = 1;
                q.push(ii(uu,vv));
                land2.push_back(ii(uu,vv));
            }
        }
    }
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            char x;
            cin >> x;
            if (x == '1') a[i][j] = 1;
            else a[i][j] = 0;
    }
    if (bfs1()) {
        cout << 0;
        return 0;
    }
    bfs2();
    ll ans = (ll)(1e15);
    for (int i = 0; i < land1.size(); i++)
        for (int j = 0; j < sz(land2); j++)
            ans = min(ans , (ll)sqr(land1[i].fir - land2[j].fir) + (ll)sqr(land1[i].sec - land2[j].sec));
    cout << ans;
    return 0;
}
