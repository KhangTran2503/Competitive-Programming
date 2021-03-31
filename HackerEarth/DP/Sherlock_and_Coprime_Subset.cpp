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
vector<int> prime;
vector<int> posprime(50);
vector<vector<int> > state(51);
vector<vector<int>> bitn(51);
int Maxsize;
int T;

bool check(int x){
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

vector<int>  getmask(int x){
    vector<int> d;
    for (int i = 0; i < prime.size(); i++){
        if (x < prime[i]*prime[i]) break;
        while (x % prime[i] == 0){
            d.pb(posprime[prime[i]]);
            x /= prime[i];
        }
    }
    if (x > 1) d.pb(posprime[x]);
    sort(all(d));
    uni(d);
    return d;
}

void Init(){

    for (int i = 2; i <= 50; i++)
        if (check(i)) {
            prime.pb(i);
            posprime[i] = prime.size() - 1;
        }

    Maxsize = prime.size();
    for (int i = 2; i <= 50; i++){
        bitn[i] = getmask(i);
        for (int mask = 0; mask < (1 << Maxsize); mask ++){
            bool ok = true;
            for (int x: bitn[i])
                if (getbit(mask,x)){
                    ok = false;
                    break;
                }
            if (ok) state[i].push_back(mask);
        }

    }

}

// dp[i][mask] la day lnn nhat chon cac so tu 0 -> i co trang thai la mask
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    Init();
    while (T--){
        int n;
        cin >> n;
        int num1 = 0;
        vector<int> a;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x == 1) num1 ++;
            else a.push_back(x);
        }
        if (a.empty()) {
            cout << num1 << '\n';
            continue;
        }
        sort(all(a));
        uni(a);
        n = a.size();
        vector<int> dp;
        dp.resize((1 << Maxsize));
        int ans = 1;
        for (int i = 0; i < n; i++){
            for (int mask: state[a[i]]){
                //dp[i][mask] = 1;
                int nextmask = mask;
                for (int p: bitn[a[i]]) nextmask = turnbit(nextmask,p);
                dp[nextmask] = max(dp[nextmask], dp[mask] + 1);
                ans = max(dp[nextmask], ans);
            }
        }

        cout << ans + num1 << '\n';
    }
    return 0;
}
