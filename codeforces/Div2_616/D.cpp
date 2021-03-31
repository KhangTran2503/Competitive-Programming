// Read Tutorial 616

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
    int n = s.size();
    vector<vector<int>> cnt(n + 1,vector<int> (26));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++){
            cnt[i + 1][j] = (j == s[i] - 'a');
            cnt[i + 1][j] += cnt[i][j];
        }
    
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[r][i] - cnt[l - 1][i]) sum++;
        if ((l == r) || (s[l - 1] != s[r - 1]) || (sum > 2)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}