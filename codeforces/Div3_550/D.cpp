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
#define N 2*int(1e5) + 5
using namespace std;
const db Pi = acos(-1);
typedef pair<int, ii> iii;
int d[N];
int a[N];
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        d[a[i]] ++;
    }

    int Max = 0;
    int Max1 = 0;
    for (int i = 0; i < N; i++)
        if (d[i] > Max1){
            Max1 = d[i];
            Max = i;
        }
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (a[i] == Max) q.push(i);
    vector<iii> ans;
    while (!q.empty()){
        int id = q.front();
        q.pop();
        if (id + 1 <= n){
            if (a[id + 1] > a[id]){
                ans.pb(iii(2,ii(id + 1,id)));
                q.push(id + 1);
            }
            if (a[id + 1] < a[id]){
                ans.pb(iii(1,ii(id + 1,id)));
                q.push(id + 1);
            }
            a[id + 1] = a[id];
        }
        if (id - 1 >= 1){
            if (a[id - 1] > a[id]){
                ans.pb(iii(2,ii(id - 1,id)));
                q.push(id - 1);
            }
            if (a[id - 1] < a[id]){
                ans.pb(iii(1,ii(id - 1,id)));
                q.push(id - 1);
            }
            a[id - 1] = a[id];
        }
    }

    cout << ans.size() << '\n';
    for (iii x : ans) cout << x.fir << ' ' << x.sec.fir << ' ' << x.sec.sec << '\n';
    return 0;
}
