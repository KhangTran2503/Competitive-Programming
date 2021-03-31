/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<ii>
#define matrix vector<vector<ll>>
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
using namespace std;
const int INF = int(1e9);
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n % 4 == 0 || n % 4 == 3){
        cout << "YES\n";
        vi part1, part2;
        int r = n % 4;
        n -= r;
        if (r) part1.eb(1), part1.eb(2), part2.eb(3);
        for (int i = 1; 2*i <= n; i++)
            if (i & 1) part1.eb(i + r), part1.eb(n + 1 - i + r);
            else part2.eb(i + r), part2.eb(n + 1 - i + r);
        cout << sz(part1) << '\n';
        for (int x: part1) cout << x << ' ';
        cout << '\n';
        cout << sz(part2) << '\n';
        for (int x: part2) cout << x << ' ';
    }
    else cout << "NO";
    return 0;
}