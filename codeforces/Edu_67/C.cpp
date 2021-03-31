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
typedef pair<int,ii> iii;
vector<ii> seg0;
vector<bool> good;
vector<int> a;
int n, m;

void Solve(){
    for (ii lr: seg0){
        int l = lr.fir, r = lr.sec;
        bool ok = false;
        for (int i = l; i < r; i++)
            if (a[i] > a[i + 1]){
                ok = true;
                break;
            }
        if (!ok){
            cout << "NO";
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    seg.resize(m);
    good.resize(n + 1);
    a.resize(n + 1);

    for (int i = 0; i < m; i++){
        int t, l, r;
        cin >> t >> l >> r;
        seg0.push_back(ii(l,r));
        for (int j = l; j <= r; j++) good[j] = 1;
    }

    a[1] = 50000;
    for (int i = 2; i <= n; i++)
        if (good[i]) a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;

    Solve();

    return 0;
}
