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
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    if (n % 4 == 0){
        cout << 0 <<'\n';
        cout << n/2 <<' ';
        for (int i = 1; i <= (n/2); i+=2) cout << i << ' ' << n+1-i << ' ';
        return 0;
    }
    if (n % 4 == 1){
        cout << 1 << '\n';
        cout << n/2 << ' ';
        for (int i = 2; i <= (n/2); i+=2) cout << i << ' ' << n+2-i<<' ';
        return 0;
    }
    if (n % 4 == 2){
        cout << 1 << '\n';
        cout << n/2 << ' ' << n/2 << ' ';
        for (int i = 1; i < n/2; i+=2) cout << i <<' '<<n+1-i << ' ';
        return 0;
    }

    cout << 0 << '\n';
    cout << n/2+1 << ' ' << 1 << ' ' << 2 << ' ';
    for (int i = 4; i < (n-3)/2+3; i+=2) cout << i << ' ' << n+4-i << ' ';
    return 0;
}
