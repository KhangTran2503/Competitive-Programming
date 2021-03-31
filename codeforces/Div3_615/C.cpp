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

bool Find(int n,int &x1,int &x2,int &x3){
    vector<int> num;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0){
           num.pb(i);
           n /= i;
           if (num.size() == 2) break;
        }
    if (n > 1) num.pb(n);
    x1 = num[0];
    x2 = num[1];
    x3 = num[2];
    sort(all(num));
    uni(num);
    return (num.size() == 3);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int ans1, ans2, ans3;
        if (Find(n,ans1,ans2,ans3)){
            cout << "YES\n";
            cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
        }
        else cout << "NO\n";
    }
    return 0;
}