/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
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
#define N 5005
using namespace std;
vi d[N];
int a[N],c[N];
int n, k;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        d[a[i]].pb(i);
    }
    for (int i = 1; i <= 5000; i++)
        if (d[i].size() > k){
            cout << "NO";
            return 0;
        }
    int color = 0;
    for (int i = 1; i <= 5000; i++)
        if (!d[i].empty()) {
            for (int id : d[i]){
                color = (color+1)%(k+1);
                if (color == 0) color = 1;
                c[id] = color;
            }
        }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << c[i] << ' ';
    return 0;
}
