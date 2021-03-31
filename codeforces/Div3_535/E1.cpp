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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define N 305
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int a[N];
int b[N];
int l[N], r[N];
int n, m;

bool inrange(int x,int l, int r){
    if (x >= l && x <= r) return true;
    return false;
}

/// Duyet Trau , Gia su giam a[i] thanh so nho nhat co the va so sanh

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
    int ans1 = 0;
    vi ans2;
    for (int i = 1; i <= n; i++){
        for (int i = 1; i <= n; i++) b[i] = a[i];
        vi tmp;
        for(int j = 1; j <= m; j++)
            if (inrange(i,l[j],r[j])){
                tmp.pb(j);
                for (int k = l[j]; k <= r[j]; k++) b[k]--;
            }
        int tmp2 = *max_element(b+1,b+1+n) - b[i];
        if (tmp2 > ans1){
            ans1 = tmp2;
            ans2 = tmp;
        }


    }
    cout << ans1 << '\n';
    cout << sz(ans2) << '\n';
    for (int x: ans2) cout << x << ' ';

    return 0;
}
