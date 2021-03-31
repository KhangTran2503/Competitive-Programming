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
using namespace std;
const db Pi = acos(-1);
int q;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> q;
    while (q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool ok = false;
        for (int i = x1; i <= y1; i++){
            for(int j = x2; j <= x2; j++)
                if (i != j){
                    cout << i << ' ' << j <<'\n';
                    ok = true;
                    break;
                }
            if (ok) break;
        }
    }

    return 0;
}
