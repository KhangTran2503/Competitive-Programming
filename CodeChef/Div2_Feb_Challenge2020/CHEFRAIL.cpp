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
const ll MaxN = (ll)(1e5) + 1;
vector<int> minprime(MaxN);
vector<vector<int>> part(MaxN), h(MaxN);
vector<ll> need(MaxN);
vector<ll> square;
vector<bool> cntposx(MaxN,false), cntposy(MaxN,false),cntnegx(MaxN,false), cntnegy(MaxN,false);

ll _sqrt(ll x){ 
    ll _x = trunc(sqrt(x));
    if (_x*_x == x) return _x;
    return -1;
}

void init(){
   
    for (int i = 1; i*i < MaxN; ++i) square.push_back((ll)i * (ll)i);

    minprime[1] = 1;
    for (int i = 2; i < MaxN; i++)
        if (!minprime[i]){
            minprime[i] = i;
            for (ll j = (ll)i*(ll)i; j < MaxN; j += (ll)i) minprime[j] = i;
        }

    need[1] = 1;
    for (int i = 2; i < MaxN; i++){
        unordered_map<int,int> cnt;
        int u = i;
        while (u > 1){
            cnt[minprime[u]]++;
            u /= minprime[u];
        }
        need[i] = 1;
        for (auto it: cnt)
            if ((it.second) & 1) need[i] *= (it.first);
    }

       for (int i = 1; i < MaxN; i++)
        for (int j = 0; j < square.size(); j++){
            ll x = (ll)need[i]*(ll)square[j];
            if (x >= MaxN) break;
            part[i].emplace_back(x);
            h[i].emplace_back(_sqrt(x*(ll)i));
        }
    
   
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();

    
     int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        bool zero = 0;

        
        vector<int> posx, posy, negx, negy;
        fill(all(cntposx), false);
        fill(all(cntposy), false);
        fill(all(cntnegx), false);
        fill(all(cntnegy), false);

        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x > 0) posx.emplace_back(x), cntposx[x] = true;
            if (x < 0) negx.emplace_back(-x), cntnegx[-x] = true;
            zero |= (x == 0);
        }
        
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            if (x > 0) posy.emplace_back(x), cntposy[x] = true;
            if (x < 0) negy.emplace_back(-x), cntnegy[-x] = true;
            zero |= (x == 0);
        }
        
          ll ans = 0;
          if (zero) ans = (ll)(posy.size() + negy.size())*(ll)(posx.size() + negx.size());

         for (int i = 0 ; i < int(posx.size()); i++){
            int u = posx[i];
            for (int j = 0; j < int(part[u].size()); j++)
                if (cntnegx[part[u][j]] && (h[u][j] >= 0)) ans += cntposy[h[u][j]] + cntnegy[h[u][j]];
        }
        
        for (int i = 0 ; i < int(posy.size()); i++){
            int u = posy[i];
            for (int j = 0; j < int(part[u].size()); j++)
                if (cntnegy[part[u][j]] && (h[u][j] >= 0)) ans += (ll)cntposx[h[u][j]] + (ll)cntnegx[h[u][j]]; 
        }
            
        cout << ans << '\n';
    }
    return 0;
}



