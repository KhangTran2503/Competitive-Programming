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
#define oo (ll)(1e9)
#define N int(1e5)+5
using namespace std;
int T,n;
int a[N];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 1; i<=n; i++) cin >> a[i];
        cout << a[1] <<' ';
        for (int i = 2 ; i <= n; i++) cout << lcm(a[i],a[i-1]) << ' ';
        cout << a[n] << '\n';
    }
    return 0;
}
