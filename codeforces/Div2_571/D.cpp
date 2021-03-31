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
int n;

/// sigma(1 -> n) a[i] = 0  <=> sigma(1->n)floor(a[i]) + sigma(1->n)e[i]
/// voi 0 < ei < 1
// used[i] danh dau nhung so nguyen
// con lai la tang giam theo diff

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vector<db> a(n);
    vector<int> ans(n);
    vector<bool> used(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll diff = 0;
    for (int i = 0; i < n; i++){
        if (floor(a[i]) == ceil(a[i])) used[i] = 1;
        ans[i] = floor(a[i]);
        diff += ans[i];
    }

    for (int i = 0; i < n && diff < 0; i++)
        if (!used[i]){
            ans[i] += 1;
            diff += 1;
        }
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}
