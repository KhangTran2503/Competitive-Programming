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
#define N 5*int(1e6)+5
using namespace std;
const db Pi = acos(-1);
int okprime[N] = {0};
ll f[N];
int t;

void Era(){
    for (int i = 2; i*i <= N-5; i++)
        if (!okprime[i])
            for (int j = i*i; j <= N-5; j+=i) okprime[j] = i;

    for (int i = 2; i <= N-5; i++){
        int u = i;
        while (okprime[u]){
            f[i]++;
            u /= okprime[u];
        }
        if (u > 1) f[i]++;
        f[i] += f[i-1];
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> t;
    Era();
    while (t--){
        int a , b;
        cin >> b >> a;
        if (a == b) cout << 0 << '\n';
        else cout << f[b] - f[a] << '\n';
    }
    return 0;
}
