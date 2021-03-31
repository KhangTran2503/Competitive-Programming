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
ll cnt3[105][105][105];
ll cnt2_1[105][105], cnt2_2[105][105], cnt2_3[105][105];
ll cnt1_1[105], cnt1_2[105], cnt1_3[105];
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int x, y , z;
        cin >> x >> y >> z;
        ans += 3*cnt3[x][y][z];
        ans += cnt1_1[x] + cnt1_2[y] + cnt1_3[z];
        ans -= 2*(cnt2_1[x][y] + cnt2_2[y][z] + cnt2_3[z][x]);
        cnt3[x][y][z] ++;
        cnt1_1[x]++; cnt1_2[y]++; cnt1_3[z]++;
        cnt2_1[x][y]++; cnt2_2[y][z]++; cnt2_3[z][x]++;
    }
    cout << ans;
    return 0;
}
