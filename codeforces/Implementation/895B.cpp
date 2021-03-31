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
map<int,ll> d1;
map<int,ll> cnt;
int n,x,k;
ll res = 0;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> x >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        d1[a[i]/x] ++;
    }
    for (int i = 0; i < n; i++){
        int y = (a[i] - 1)/x;
        res += d1[y+k];
    }
    cout << res << '\n';
    sort(rall(a));
    uni(a);
    for (int i = 0; i < sz(a); ){
        int j = i;
        ll tmp = 1;
        while (j < sz(a) && (a[i])/x + k == (a[j]-1)/x){
            tmp *= cnt[a[j]];
            j++;
        }
        if (j != i) res -= tmp;
        i = j;
    }
    cout << res;
    return 0;
}
