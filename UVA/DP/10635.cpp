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
using namespace std;
const db Pi = acos(-1);
int id[255*255];
int T, n, p, q;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++){
        cin >> n >> p >> q;
        ms(id,0);
        for (int i = 1; i <= p+1; i++){
            int x;
            cin >> x;
            id[x] = i;
        }
        vi f;
        for (int i = 1; i <= q+1; i++){
            int x;
            cin >> x;
            if (id[x] != 0){
                auto it = upper_bound(all(f),id[x]);
                if (it == f.end()) f.pb(id[x]);
                else *it = id[x];
            }
        }
        cout << "Case " << t <<": " << f.size() << '\n';

    }

    return 0;
}
