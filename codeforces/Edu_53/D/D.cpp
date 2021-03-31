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
#define N 2*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
ll a[N], T;
int n;
ll fen[N];
int fend[N];

void update1(int x,ll val){
    for (int i = x; i <= n; i+= (i & -i)) fen[i]+= val;
}

void update2(int x,int val){
    for (int i = x; i <= n; i+= (i & -i)) fend[i]+= val;
}

ll get1(int x){
    ll sum = 0;
    for (int i = x; i > 0; i-=(i & -i)) sum += fen[i];
    return sum;
}
int get2(int x){
    int sum = 0;
    for (int i = x; i > 0; i-=(i & -i)) sum += fend[i];
    return sum;
}

int Find(ll x){
    int l = 0, r = n;
    int id = -1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (get1(mid) <= x){
            id = mid;
            l = mid+1;
        }
        else r = mid -1;
    }
    return id;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> T;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update1(i,a[i]);
        update2(i,1);
    }

    ll ans = 0;
    while (1){
        int idx = Find(T);
        //cout << idx << '\n';
        if (idx == -1) break;
        if (idx == n){
            ll Sumn = get1(n);
            if (Sumn == 0) break;
            ans += (T/Sumn)*(ll)get2(n);
            T -= (T/Sumn)*Sumn;
            continue;
        }
        update1(idx+1,-a[idx+1]);
        update2(idx+1,-1);

    }
    cout << ans;
    return 0;
}
