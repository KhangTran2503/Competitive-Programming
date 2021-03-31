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
#define getbit(s,k) ((s >> k) & 1)
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
int n;

bool check(int s){
    s ++;
    while (s % 2 == 0) s /= 2;
    return (s == 1);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    int pos = 0;
    for (int i = 0; i < 30; i++)
        if (getbit(n,i)) pos = i;
    vector<int> ans_;

        for (int i = pos ; i >= 0; i--){
            if (check(n)) break;

            if (!getbit(n,i)){
                ans++;
                //cout << n << '\n';
                n = n ^ ((1 << (i + 1)) - 1);
                //cout << n << '\n';
                ans_.pb(i + 1);
                if (check(n)) break;
                n++;
                ans ++;
                //cout << n << '\n';
                if (check(n)) break;
            }

        }

    cout << ans << '\n';
    for (auto x : ans_) cout << x << ' ';
    return 0;
}
