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
int q;

ll calc(ll k,ll n,ll a,ll b){
    ll ans;
    if ((k-n*b)%(a-b)==0) ans=(k-n*b)/(a-b)-1;
    else ans=(k-n*b)/(a-b);
    if (b*n>=k) return -1;
    else return min(n,ans);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int q;

    cin>>q;
    while (q--){
        ll a, b, n, k;
        cin >> k >> n >> a >> b;
        cout << calc(k,n,a,b) << '\n';
    }
}
