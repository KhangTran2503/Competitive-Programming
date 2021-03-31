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
set<int> ele[6];
int n;

bool check(int x){
    int tmp ;
    auto it = ele[1].upper_bound(x);
    if (it == ele[1].end()) return false;
    tmp = *it;
    ele[1].erase(it);
    it = ele[2].upper_bound(tmp);
    if (it == ele[2].end()) return false;
    tmp = *it;
    ele[2].erase(it);
    it = ele[3].upper_bound(tmp);
    if (it == ele[3].end()) return false;
    tmp = *it;
    ele[3].erase(it);
    it = ele[4].upper_bound(tmp);
    if (it == ele[4].end()) return false;
    tmp = *it;
    ele[4].erase(it);
    it = ele[5].upper_bound(tmp);
    if (it == ele[5].end()) return false;
    ele[5].erase(it);
    return true;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x == 4) ele[0].insert(i);
        if (x == 8) ele[1].insert(i);
        if (x == 15) ele[2].insert(i);
        if (x == 16) ele[3].insert(i);
        if (x == 23) ele[4].insert(i);
        if (x == 42) ele[5].insert(i);
    }

    int ans = 0;
    for (int x : ele[0])
        if (!check(x)) break;
        else ans += 6;
    //cout << ans << '\n';
    cout << n - ans;

    return 0;
}
