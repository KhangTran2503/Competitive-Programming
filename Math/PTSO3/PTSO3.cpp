/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector
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

int T;
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n;
        n*=2;
        bool ok = false;
        for (int i = 2 ; i <= int(sqrt(n)); i++)
            if (n % i == 0){
                int small = i;
                int big = n/i-1;
                if ((big-small) % 2 == 0){
                    int x = (big-small)/2;
                    int y = (big+small)/2;
                    cout << n/2 <<" = " << x+1 <<' ';
                    for (int i = x+2; i <= y; i++) cout << "+ "<<i <<' ';
                    cout << '\n';
                    ok = true;
                    break;
                }
            }
        if (!ok) cout << -1 <<'\n';
    }

    return 0;
}
    
