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
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    int l = 0, r = s.size() - 1;
    vector<int> t1, t2;
    while (1) {
        while (l < s.size() && s[l] != '(') l++;
        while (r > l && s[r] != ')') r--;
        if (r <= l) break;
        t1.eb(l++);
        t2.eb(r--);
    }
    if (t1.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    cout << 1 << '\n';
    cout << int(t1.size())*2 << '\n';
    for (int x: t1) cout << x + 1 << ' ';
    reverse(all(t2));
    for (int x: t2) cout << x + 1 << ' ';
    return 0;
}