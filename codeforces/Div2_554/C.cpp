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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b)))*(ll)(b)
#define gcd(a,b) __gcd((ll)(a),(ll)(b))
#define oo (ll)(1e17)
using namespace std;
const db Pi = acos(-1);
ll a, b;
ll lcmans, ans;



void process(ll x){
    //ll t = a % x;
    //cout << x << ' ';
    //if (t > 0) t = x - t;
    ll t = (a/x + (a % x != 0)) * x - a; //  Find k such (a + k) = qx, k min
    //cout << t << ' ';
    ll lcm_c = lcm(a + t, b + t);
    //cout << a + t << ' ' << b + t << ' ';
    //cout << lcm_c << '\n';
    if (lcm_c < lcmans || (lcm_c == lcmans && t < ans)){
        lcmans = lcm_c;
        ans = t;
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> a >> b;
    if (a == b){
        cout << 0;
        return 0;
    }
    // gcd (a + k, b + k) = gcd(b - a, a + k);
    // nhung uoc cua abs(b- a) co the la gcd() => tu do tim a + k sao cho i | (a + k)

    lcmans = lcm(a,b);
    ans = 0;
    ll delta = abs(a - b);
    for (ll i = 1; i*i <= delta; i++){
        if (delta % i == 0){
            process(i);
            process(delta / i);
        }
    }

    cout << ans;


    return 0;
}
