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
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 2*int(1e5) + 5
using namespace std;
const db Pi = acos(-1);
int a[N], b[N];
int n;
int ans = 0;
map<ii,int> cnt;

int sign(int x){
    return (int)x/abs(x);
}



int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++){
        if (a[i] == 0 && b[i] != 0) continue;
        if (a[i] != 0 && b[i] == 0){ /// xet TH nhung cai b = 0
            cnt[ii(1,0)]++;
            continue;
        }
        if (a[i] == 0 && b[i] == 0){
            ans++;
            continue;
        }
        int sign1 = sign(a[i]);
        int sign2 = sign(-b[i]);
        int d = gcd(abs(a[i]), abs(b[i]));
        cnt[ii(sign1*sign2*abs(a[i])/d , abs(b[i])/d)]++; /// bo phan so -b[i] , a[i] vao map dem
    }
    int maxx = 0;
    for (auto x: cnt) maxx = max(maxx, x.second);
    ans += maxx;
    cout << ans;
    return 0;
}
