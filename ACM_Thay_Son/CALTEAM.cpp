/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e5)+5
using namespace std;
typedef pair<ll,ii> iii;
char s[N];
ll a[N];
int n;
set<int> id;
priority_queue<iii, vector<iii> , greater<iii> > pq;
bool ok[N]={0};
vector<ii> ans;


//// bug 
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        id.insert(i);
    }
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++)
        if (s[i] != s[i+1]) pq.push(iii(abs(a[i]-a[i+1]),ii(i,i+1)));

    while(!pq.empty()){
        ll w = pq.top().fir;
        int u = pq.top().sec.fir,
            v = pq.top().sec.sec;
        pq.pop();
        if (ok[u] || ok[v]) continue;

        int id1,id2;
        if (*(id.begin()) != u && *(id.rend()) != v){
            id2 = *id.upper_bound(v);
            id1 = *(--id.lower_bound(u));
            pq.push(iii(abs(a[id2]-a[id1]),ii(id1,id2)));
        }
        ans.pb(ii(u,v));
        ok[u] = ok[v] = 1;
        id.erase(id.find(u));
        id.erase(id.find(v));


    }

    cout << ans.size() << '\n';
    for (ii x: ans) cout << x.fir << ' ' << x.sec << '\n';
    return 0;
}
