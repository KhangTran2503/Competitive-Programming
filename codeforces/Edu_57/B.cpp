/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const ll Mod = 998244353;
int n;
string s;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s;
    ll begin = 1;
    ll last = 1;
    for (int i = 0; i < n-1 && s[i] == s[i+1]; i++) begin++;
    for (int i = n-1 ; i > 1 && s[i] == s[i-1]; i--) last++;
    if (s[0] != s[n-1]){
        cout << (begin+last+1)%Mod;
    }
    else {
        if (begin == n)
        {
            cout<< ((begin)*(begin+1)/2)%Mod;
            return 0;
        }
        cout << ((last+1)*(begin+1))%Mod;
    }
    return 0;
}
