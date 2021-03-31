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
#define matrix vector<vector<ll>>
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
using namespace std;
const int INF = int(1e9);
int n;
// (x | y) - y = x & (~y)

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    int fand ;
    for (int &i: a) cin >> i;
    vector<int> lef(n);
    vector<int> rig(n);
    lef[0] = (~a[0]);
    for (int i = 1; i < n; i++) lef[i] = (lef[i - 1] & (~a[i]));
    rig[n - 1] = (~a[n - 1]);
    for (int i = n - 2; i >= 0; i--) rig[i] = (rig[i + 1] & (~a[i]));
    

    int maxpos = 0;
    int maxans = a[0];
    if (n > 1) maxans &= rig[1];
    for (int i = 1; i < n; i++){
        int tmp = a[i] & lef[i - 1];
        if (i + 1 < n) tmp &= rig[i + 1];
        if (tmp > maxans){
            maxans = tmp;
            maxpos = i;
        }
    }
    cout << a[maxpos] << ' ';
    for (int i = 0; i < n; i++)
        if (i != maxpos) cout << a[i] << ' ';
    return 0;
}