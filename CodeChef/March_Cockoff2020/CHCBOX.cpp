/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
int t;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(2*n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n + 1; i <= 2*n; i++) a[i] = a[i - n];
        int maxa = *max_element(a.begin() + 1,a.begin() + n);
        priority_queue<ii> pq;
        int ans = 0;
        for (int i = 1; i < n/2; i++) pq.push({a[i],i});
        for (int i = n/2; i < n + n/2; i++){
            while (!pq.empty() && pq.top().sec <= i - n/2) pq.pop();
            pq.push({a[i],i});
            if (pq.top().fir < maxa) ans++;
        } 
        cout << ans << '\n';
    }
    return 0;
}