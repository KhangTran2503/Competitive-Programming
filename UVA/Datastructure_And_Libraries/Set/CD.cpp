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
using namespace std;
int n, m;
set<int> s;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    while ( cin >> n >> m){
        if (m == 0 && n == 0) break;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        int res = 0;

        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            if (s.find(x)!=s.end()) res++;
        }
        cout << res << '\n';
        s.clear();

    }

    return 0;
}
