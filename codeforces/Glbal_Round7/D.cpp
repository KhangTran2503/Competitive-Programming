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
const ll base2 = 31;
const ll base1 = 551;
const ll Mod = (ll)(1e9) + 7;
typedef pair<ll,ll> pll;
vector<pair<ll,ll>> hashlef,hashrig,hpow; 


// Hash
void Init(const string & t){
    int m = sz(t);
    hashlef.resize(m + 2);
    hashrig.resize(m + 2);
    hpow.resize(m + 2);

    hpow[0] = {1LL,1LL};
    for (int i = 1; i <= m; i++){
        hpow[i].fir = (hpow[i - 1].first*base1) % Mod;
        hpow[i].sec = (hpow[i - 1].sec*base2);
    }

    hashlef[0] = {0LL,0LL};
    hashrig[m + 1] = {0LL,0LL};
    for (int i = 1; i <= m; i++){
        hashlef[i].fir = (hashlef[i - 1].fir*base1 + t[i - 1] - 'a' + 1 + Mod) % Mod;
        hashlef[i].sec = (hashlef[i - 1].sec*base2 + t[i - 1] - 'a' + 1);
        hashrig[m + 1 - i].fir = (hashrig[m + 2 - i].fir*base1 + t[m - i] - 'a' + 1 + Mod) % Mod;
        hashrig[m + 1 - i].sec = (hashrig[m + 2 - i].sec*base2 + t[m - i] - 'a' + 1);
    }
}

pll gethash(int L,int R,int flip){
    if (!flip){
        pll ans;
        ans.fir = (hashlef[R].fir - hashlef[L - 1].fir*hpow[R - L + 1].fir + Mod*Mod) % Mod;
        ans.sec = (hashlef[R].sec - hashlef[L - 1].sec*hpow[R - L + 1].sec );
        return ans;
    }
    else {
        pll ans;
        ans.fir = (hashrig[L].fir - hashrig[R + 1].fir*hpow[R - L + 1].fir + Mod*Mod) % Mod;
        ans.sec = (hashrig[L].sec - hashrig[R + 1].sec*hpow[R - L + 1].sec);
        return ans;
    }
}


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int lef = 0, rig = n - 1;
    while (lef < rig){
        if (s[lef] != s[rig]) break;
        lef++, rig--;
    }
    if (lef) cout << s.substr(0,lef);
    if (n > 2*lef){
        string t = s.substr(lef,n - 2*lef);
        //cout << t;
        Init(t);
        int m = sz(t);
        for (int len = m; len >= 1; len--){
            if (gethash(1,len,0) == gethash(1,len,1)){
                cout << t.substr(0,len);
                break;
            }
            if (gethash(m - len + 1,m,0) == gethash(m - len + 1,m,1)){
                cout << t.substr(m - len,len);
                break;
            }
        }

    }
    if (lef) cout << s.substr(n - lef,lef);
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}