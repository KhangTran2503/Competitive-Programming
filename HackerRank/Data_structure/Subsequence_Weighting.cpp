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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 150005
using namespace std;
const db Pi = acos(-1);
int w[N], a[N];
ll ST[4*N] = {0};
int n, T;

void update(int id,int l,int r,int pos,ll val){
    if (l > r || pos < l || pos > r) return;
    if (l == r){
        ST[id] = max(ST[id],(ll)val);
        return;
    }
    int mid = (l+r) >> 1;
    update(2*id, l, mid, pos, val);
    update(2*id+1, mid+1, r, pos, val);
    ST[id] = max( (ll)ST[2*id] , (ll)ST[2*id+1]);
}

ll get(int id,int l,int r,int u,int v){
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return ST[id];
    int mid = (l+r) >> 1;
    return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}

int get_id(vi x,int val){
    return upper_bound(all(x),val) - x.begin();
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n;
        vi b;
        ms(ST,0);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            b.pb(a[i]);
        }
        for (int i = 1; i <= n; i++) cin >> w[i];
        sort(all(b));
        uni(b);
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            int id = get_id(b,a[i]);
            //cout << id << ' ';
            ll Maxval = get(1,0,n,0,id-1);
            //cout << Maxval << ' ';
            ll f = Maxval + w[i];
            //cout << f << '\n';
            update(1,0,n,id,f);
            ans = max(ans , f);
        }
        cout << ans << '\n';

    }

    return 0;
}
