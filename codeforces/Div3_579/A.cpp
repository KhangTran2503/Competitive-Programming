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
int q;

bool check(const vector<int> &a){
    //int cur = 1;
    int pos = -1;
    int n = a.size();
    for (int i = 0; i < n; i++)
        if (a[i] == 1){
            pos = i;
            break;
        }

    bool ok1 = true;
    for (int len = 0; len < n; len++)
        if (a[(pos + len) % n] != len + 1){
            ok1 = false;
            break;
        }

    bool ok2 = true;
    for (int len = 0; len < n; len++)
        if (a[(pos - len + n) % n] != len + 1){
            ok2 = false;
            break;
        }
    return (ok1 || ok2);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        if (check(a)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}