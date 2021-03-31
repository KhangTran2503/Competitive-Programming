#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector
#define fir first
#define sec second
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (int)(1e9)
#define N 1005
using namespace std;
ii X[3];
int Map[N][N]={0};
ii Center;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> X[0].fir >> X[0].sec;
    cin >> X[1].fir >> X[1].sec;
    cin >> X[2].fir >> X[2].sec;

    int ans = oo;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++){
            int tmp = 0;
            for (int k = 0; k < 3; k++)
                tmp += abs(X[k].fir-i) + abs(X[k].sec-j);
            if (tmp < ans){
                Center = ii(i,j);
                ans = tmp;
            }
        }

    Map[Center.fir][Center.second] = 1;
    for (int i = 0; i < 3; i++){
        int r = Center.fir, c = Center.sec;
        while (r > X[i].fir) Map[--r][c] = 1;
        while (r < X[i].fir) Map[++r][c] = 1;
        while (c > X[i].sec) Map[r][--c] = 1;
        while (c < X[i].sec) Map[r][++c] = 1;
    }

    cout << ans+1 <<'\n';
    for(int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if (Map[i][j]) cout<< i << ' ' <<j <<'\n';

    return 0;
}
