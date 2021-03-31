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
int d[N];
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        d[a[i]] ++;
    }

    vector<int> sq1;
    vector<int> sq2;
    for (int i = 0; i < n; i++){
        if (d[a[i]] > 2) {
            cout << "NO";
            return 0;
        }

        if (d[a[i]] == 2){
            sq1.pb(a[i]);
            sq2.pb(a[i]);
            d[a[i]] = 0;
        }

        if (d[a[i]] == 1){
            sq1.pb(a[i]);
            d[a[i]] = 0;
        }
    }

    cout << "YES\n";
    sort(all(sq1));
    sort(rall(sq2));

    cout << sz(sq1) << '\n';
    for (auto x: sq1) cout << x << ' ';
    cout << '\n';

    cout << sz(sq2) << '\n';
    for (auto x: sq2) cout << x << ' ';
    cout << '\n';

    return 0;
}
