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
vector<vector<int>> cnt;
vector<int> cnt2(26);
string s;
int n, m;

bool check(int mid){
    for (int i = 0; i < 26; i++)
        if (cnt[mid][i] < cnt2[i]) return false;
    return true;
}

int Solve(string t){
    for (int i = 0; i < 26; i++) cnt2[i] = 0;
    for (int i = 0; i < t.size(); i++)
        cnt2[t[i] - 'a'] ++;

    int ans = 0, l = 1, r = n;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            ans = mid;
            //cout << ans << '\n';
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s;
    cnt.resize(n + 1,vector<int> (26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][s[i] - 'a'] = cnt[i][s[i] - 'a'] + 1;
    }

    cin >> m;
    while (m--){
        string t;
        cin >> t;
        cout << Solve(t) << '\n';
    }
    return 0;
}
