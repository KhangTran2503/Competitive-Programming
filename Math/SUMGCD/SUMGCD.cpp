/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e6)+5
using namespace std;
int T;
int phi[N]={0}, okprime[N]={0};
ll f[N]={0LL};

void Phi_Euler(){

    okprime[1] = 1;
    for (int i = 2; i <= 1000000; i++){
        if (okprime[i] == 0){
            okprime[i] = i;
            if (i <= 1000)
                for (int j = i*i; j <= 1000000; j+=i) okprime[j] = i;
        }
        int fac = i;  ///tinh phi ham Euler
        int u = i;
        int d = okprime[i];
        while (u % d == 0){
            fac -= fac/d;
            while (u % d == 0) u/=d;
            d = okprime[u];
            if (d == 1) break;
        }
        if (u > 1) fac-= fac/u;
        phi[i] = fac;
    }

    for (int i = 1; i <= 500000; i++)
        for (int j = 2*i; j <= 1000000; j+=i)
            f[j] += (ll)phi[j/i]*(ll)i;

    for (int i = 1; i <= 1000000; i++) f[i] += f[i-1];
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    Phi_Euler();
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cout << f[n] << '\n';
        //cout << phi[n] << '\n';
    }
    return 0;
}
