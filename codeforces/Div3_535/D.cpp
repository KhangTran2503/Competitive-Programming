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
#define oo (ll)(1e9)
#define N 2*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
char s[N];
int n;
char kt[] = {'B','G','R'};

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 2; i < n; i++){
        if (s[i] == s[i-1]){
            ans ++;
            for (int c = 0; c < 3; c++)
                if (kt[c] != s[i-1] && kt[c] != s[i+1]){
                    s[i] = kt[c];
                    break;
                }
        }
    }
    if (s[n] == s[n-1]){
        ans++;
        for (int c = 0; c < 3; c++)
            if (kt[c] != s[n-1]){
                s[n] = kt[c];
                break;
            }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) cout << s[i];

    return 0;
}
