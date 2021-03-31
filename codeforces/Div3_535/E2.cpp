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
#define oo (ll)(1e9)
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
int n,q;
int s[N], a[N];
vi point;
vii seg;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        seg.pb(ii(l,r));
        point.pb(l);
        point.pb(r);
    }
    sort(all(point));
    uni(point);
    int Pos;
    int ans = *max_element(a+1,a+1+n) - *min_element(a+1,a+1+n);
    for (int i = 0; i < sz(point); i++){
        for (int j = 0; j < q; j++)
            if (point[i] >= seg[j].fir && point[i] <= seg[j].sec)
                s[seg[j].fir]--, s[seg[j].sec + 1] ++;
        vi f;
        for (int i = 1; i <= n; i++){
            s[i] += s[i-1];
            f.pb(s[i] + a[i]);
        }
        int tmp = *max_element(all(f)) - *min_element(all(f));
        if (tmp > ans){
            ans = tmp;
            Pos = point[i];
        }
        ms(s,0);
    }
    cout << ans << '\n';
    vi ans2;
    for (int i = 0; i < q; i++)
        if (Pos >= seg[i].fir && Pos <= seg[i].sec) ans2.pb(i);
    cout << sz(ans2) << '\n';
    for (int x : ans2) cout << x+1 << ' ';

    return 0;
}
