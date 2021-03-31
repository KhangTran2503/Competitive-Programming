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
int q, n;

void Solve(){
    cin >> n;
    vector<ii> a(n);
    int M = 0;
    for (int i = 0; i < n; i++){
         cin >> a[i].fir >> a[i].sec;
         M = max(M, a[i].fir);
    }

    vector<int> cnt1(M + 1); // tao 1 mang dem so luong a[i].fir
    vector<int> cnt2(M + 1); // moi so a[i].fir dem so luong so 1
    for (int i = 0; i < n; i++){
        cnt1[a[i].fir] ++;
        cnt2[a[i].fir] += a[i].sec;
    }
    a.clear();
    for (int i = 0; i < cnt1.size(); i++)
        if (cnt1[i] > 0) a.pb(ii(cnt1[i],cnt2[i]));

    n = a.size();
    sort(rall(a)); // sort cho a[i].fir giam dan
    ll ans1 = 0, ans2 = 0;
    ll w = a[0].fir;
    int start = 0;
    priority_queue<ii> pq; // dung heap de chon cac so co a[i].fir >= w de tim a[i].sec max
    while (1){
        while (start < n && a[start].fir >= w){  // day cac a[i].fir >= w vao heap
            pq.push(ii(a[start].sec,a[start].fir));
            start ++;
        }
        if (!pq.empty()){
            ii u = pq.top();
            pq.pop();
            ans1 += min((ll)u.sec,w); // lay ptu co u.fir lon nhat (nhieu so 1) -> chon u.sec nao cx dc
            ans2 += min((ll)u.fir,w); // lay toi da cac so 1
        }
        w--;  // giam w
        if (w == 0) break;
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> q;
    while (q--){
        Solve();
    }

    return 0;
}
