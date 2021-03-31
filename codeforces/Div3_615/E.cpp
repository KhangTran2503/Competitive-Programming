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

int n, m;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    
    int ans = 0;
    for (int j = 0; j < m; j++){ // column dependent
        vector<int> needshift(n); // numbers needshift
        for (int i = 0; i < n; i++)
            if (a[i][j] % m == j){
                int pos = a[i][j]/m;
                if (pos < n) needshift[(i - pos + n) % n]++;
            }
        int need = n;
        for (int shift = 0; shift < n; shift++)
            need = min(need,(n - needshift[shift]) + shift);
        ans += need;
    } 
    cout << ans;
    return 0;
}