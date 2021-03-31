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

// Brach and Bound
int Solve(){
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(rall(a));
    uni(a);
    n = a.size();
    int ans = a[0];
    for (int i = 0; i < n - 1; i++) // 2 number
        if (a[i] < ans/2 || a[i] + a[i + 1] < ans) break;
        else {
            for (int j = i + 1; j < n; j++)
                if (a[i] + a[j] < ans) break;
                else {
                    if (a[i] % a[j] != 0) ans = max(ans, a[i] + a[j]);
                }
        }

    for (int i = 0; i < n - 2; i++) // 3 number
        if (a[i] < ans/3 || a[i] + a[i + 1] + a[i + 2] < ans) break;
        else {
            for (int j = i + 1; j < n - 1; j++)
                if (a[i] + a[j] + a[j + 1] < ans) break;
                else{
                    if (a[i] % a[j] == 0) continue;
                    for (int k = j + 1; k < n; k++)
                        if (a[i] % a[k] != 0 && a[j] % a[k] != 0) ans = max(ans, a[i] + a[j] + a[k]);
                }
        }
    return ans;

}


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        cout << Solve() << '\n';
    }

    return 0;
}
