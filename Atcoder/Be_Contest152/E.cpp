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
const int Maxn = int(1e6);
const ll Mod = (ll)(1e9) + 7;
int prime[Maxn + 5];
int n;

void Era(){
    for (int i = 2; i <= Maxn; i++)
        if (prime[i] == 0){
            prime[i] = i;
            if (i <= 1000){
                for (int j = i*i; j <= Maxn; j += i) prime[j] = i;
            }
        }
}

ll fastpow(ll x,ll y = Mod - 2){
    ll ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return ans;
}

ll LCM(const vector<int>& x){
    Era();
    unordered_map<int,int> power;
    for (int num: x){
        unordered_map<int,int> tmp;
        int u = num;
        while (u > 1){
            tmp[prime[u]]++;
            u /= prime[u];
        }
        for (auto it: tmp)
            power[it.first] = max(power[it.first],it.second);
    }

    ll ans = 1;
    for (auto it: power)
        ans = (ans*fastpow(it.first,it.second)) % Mod;
    return ans;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    
    // factor xi/yi = a1/ai = bi/b1
   
    ll Lcm = LCM(a);
    //cout << Lcm << '\n';
    ll ans = 0;
    for (int x: a) 
        ans = (ans + (fastpow(x)*Lcm) % Mod ) % Mod;

    cout << ans; 
    return 0;
}