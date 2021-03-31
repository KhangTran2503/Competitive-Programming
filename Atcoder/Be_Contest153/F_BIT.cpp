//use BIT to sum 1 -> i
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
vector<ll> Fen;
int n, D, A;

void Update(int id,ll val = 1){
    for (id++ ; id <= n; id += (id & - id)) Fen[id] += val;
}

ll get(int id){
    ll res = 0;
    for (id++; id > 0 ; id -= (id & -id)) res += Fen[id];
    return res; 
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> D >> A;
    vector<pair<ll,ll>> a(n);
    Fen.resize(n + 2);
    for (int i = 0; i < n; i++) cin >> a[i].fir >> a[i].sec;

    sort(all(a));
    D *= 2;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll remain = a[i].sec - get(i);
        //cout << remain << ' ';
        if (remain <= 0) {
            //cout << '\n';
            continue;
        }
        ll delta = (remain + A - 1)/A;
        //cout << delta << ' ';
        ans += delta;
        int far = upper_bound(all(a),make_pair(a[i].fir + D*1LL + 1LL,-1LL)) - a.begin();
        //cout << far + 1 << '\n';
        Update(i,delta*(ll)A);
        Update(far,-delta*(ll)A);
    }
    cout << ans;
    return 0;
}