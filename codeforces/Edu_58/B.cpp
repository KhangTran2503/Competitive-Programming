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
using namespace std;
string s;
int l = -1,r = -1 ;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < sz(s); i++)
        if (s[i] == '['){
            l = i;
            break;
        }
    for (int i = sz(s) - 1; i >= 0; i--)
        if (s[i] == ']'){
            r = i;
            break;
        }
    if (r < l || l == -1 || r == -1){
        cout << -1;
        return 0;
    }

    int l1 = -1, r1 = -1;
    for (int i = l ; i <= r; i++){
        if (s[i] == ':'){
            l1 = i;
            break;
        }
    }
    for (int i = r; i >= l; i--){
        if (s[i] == ':') {
            r1 = i;
            break;
        }
    }

    if (l1 == r1 || l1 == -1 || r1 == -1 ) cout << -1 ;
    else {
        int cnt = 0;
        for (int i = l1; i <= r1; i++)
            if (s[i] == '|') cnt++;
        cout << 4 + cnt;
    }


    return 0;
}
