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
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
int n;
int L[N] = {0}, R[N] = {0};
int a[N];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque<int> d;
    d.push_back(1);
    for (int i = 2; i <= n; i++){
        while (!d.empty() && a[i] >= a[d.back()]) d.pop_back();
        if (d.empty()) L[i] = 0;
        else L[i] = d.back();
        d.push_back(i);
    }

    d.clear();
    d.push_back(n);
    for (int i = n-1 ; i >= 1; i--){
        while (!d.empty() && a[i] >= a[d.back()]) d.pop_back();
        if (d.empty()) R[i] = 0;
        else R[i] = d.back();
        d.push_back(i);
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (res < (ll)L[i]*(ll)R[i]) res = (ll)R[i]*(ll)L[i];
    cout << res;
    /*cout << '\n';
    for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << '\n';*/
    return 0;
}
