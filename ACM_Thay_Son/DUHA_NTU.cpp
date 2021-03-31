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
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 1005
using namespace std;
const db Pi = acos(-1);
char a[N][N];
int dp1[N][N][2], dp2[N][N][2], dp3[N][N][2], dp4[N][N][2];
int n, m;

///goi dpx[i][j][2] la so luong o di qua theo huong x ma den o (i,j) theo phuong la :
///                                      0: ngang, 1: doc 

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            char x;
            cin >> x;
            a[i][j] = x;
        }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++){
            if (a[i][j] == '0') dp1[i][j][0] = dp1[i][j][1] = 0;
            else{
                    dp1[i][j][1] = dp1[i-1][j][0] + 1;
                    dp1[i][j][0] = dp1[i][j-1][1] + 1;
            }
        }


    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--){
            if (a[i][j] == '0') dp2[i][j][0] = dp2[i][j][1] = 0;
            else{
                    dp2[i][j][1] = dp2[i-1][j][0] + 1;
                    dp2[i][j][0] = dp2[i][j+1][1] + 1;
            }
        }

    for (int i = m; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            if (a[i][j] == '0') dp3[i][j][0] = dp3[i][j][1] = 0;
            else{
                dp3[i][j][1] = dp3[i+1][j][0] + 1;
                dp3[i][j][0] = dp3[i][j+1][1] + 1;
            }

    for (int i = m; i >= 1; i--)
        for (int j = 1; j <= n; j++)
        if (a[i][j] == '0') dp4[i][j][0] = dp4[i][j][1] = 0;
        else{
                dp4[i][j][1] = dp4[i+1][j][0] + 1;
                dp4[i][j][0] = dp4[i][j-1][1] + 1;
        }

    int res = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) res = max(res, dp1[i][j][0] + dp2[i][j][1] + dp3[i][j][0] + dp4[i][j][1] - 3);
    cout << res;
    return 0;
}
