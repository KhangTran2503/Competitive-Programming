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
vi d;
int a,b,n;

int Find(int x){
    int pos = -1;
    int l = 0, r = sz(d)-1;
    while (l <= r){
        int mid = (l+r)>>1;
        if (d[mid] <= x){
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return pos;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> a >> b;
    int GCD = gcd(a,b);
    for (int i = 1 ; i*i <= GCD; i++)
        if (GCD % i == 0){
            d.pb(i);
            if (GCD/i != i) d.pb(GCD/i);
        }
    sort(d.begin(),d.end());
    cin >> n;
    for (int i = 1; i <= n; i++){
        int low, high;
        cin >> low >> high;
        int pos = Find(high);
        if (pos == -1) cout << -1 << '\n';
        else{
            if (d[pos] >= low) cout << d[pos] << '\n';
            else cout << -1 << '\n';
        }

    }
    return 0;
}
