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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (int)(1e9)
#define N 2*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
string kt[7]={"BRG","BGR","RBG","RGB","GRB","GBR"};
int n;
char s[N];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    int res = N;
    string ans = "";
    for (int per = 0; per < 6; per++){
        int tmp = 0;
        for (int i = 0; i < n; i++){
            if (s[i] != kt[per][i%3]) tmp ++;
        }
        if (tmp < res){
            res = tmp;
            ans = "";
            for (int i = 0; i < n; i++)
                ans.pb(kt[per][i%3]);
        }
    }
    cout << res << '\n';
    cout << ans;
    return 0;
}
