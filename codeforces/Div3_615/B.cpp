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
int t;
vector<ii> a;

bool check(string &ans){
    sort(all(a));
    for (int i = 1; i < a.size(); i++)
        if (!(a[i].fir >= a[i - 1].fir && a[i].sec >= a[i - 1].sec)) return false;

    ans = "";
    for (int i = 1; i < a.size(); i++){
        for (int k = a[i - 1].fir ; k < a[i].fir; k++) ans.pb('R');
        for (int k = a[i - 1].sec; k < a[i].sec; k++) ans.pb('U');
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i].fir >> a[i].sec;
        string ans;
        if (check(ans)){
            cout << "YES\n";
            cout << ans << '\n';
        }
        else cout << "NO\n";
    }
    return 0;
}