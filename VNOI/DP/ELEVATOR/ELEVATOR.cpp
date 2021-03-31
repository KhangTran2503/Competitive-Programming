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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int n;
struct Ela{
    int h, c, a;
};

vector<Ela> A;
bool cmp(const Ela& u,const Ela& v){
    return (u.a < v.a);
}

/// dp[i][j] = dp[i - 1][j - A[i].h*k]
/// bai nay cap nhat nguoc , tuong tu nhu sang Era
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++){
        cin >> A[i].h >> A[i].a >> A[i].c;
    }
    sort(all(A),cmp);
    vector<bool> dp(A[n - 1].a + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = A[i].a; j >= 0; j--)
            if (dp[j]){
                for (int k = 1; k <= A[i].c; k++)
                    if (j + A[i].h*k <= A[i].a) dp[j + A[i].h*k] = 1;
                    else break;
            }
    }
    for (int i = A[n - 1].a; i >= 0; i--)
        if (dp[i]){
            cout << i << '\n';
            break;
        }

    //for (int i = 0; i < n; i++) cout << A[i].a << ' ' << A[i].h << ' ' << A[i].c << '\n';
    return 0;
}
