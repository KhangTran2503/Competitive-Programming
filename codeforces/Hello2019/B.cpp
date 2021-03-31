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
int a[20];
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int state = (1 << n)-1;
    //cout << state << '\n';
    for (int s = 0; s < state; s++){
        int tmp = 0;
        for (int i = 0; i < n; i++)
            if (s & (1 << i)) tmp += a[i+1];
            else tmp-=a[i+1];
        if ((tmp+360*16)%360 == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
