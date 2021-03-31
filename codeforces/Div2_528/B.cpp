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
#define oo (ll)(1e15)
using namespace std;
int n,k;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    ll res = oo;
    for (int i = 1 ; i < k; i++){
        if (n%i == 0){
            res=min(res,(ll)((n/i)*k+i));
        }
    }
    cout << res;
    return 0;
}
