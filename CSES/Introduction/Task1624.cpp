/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
const int Maxn = 9;
int ans = 0;
int row[9] = {0};
int diag1[20] = {0};
int diag2[20] = {0};
vector<vector<char>> a;

bool valid(int r,int c){
    return (row[r] == 0) && (diag1[r + c] == 0) && (diag2[r - c + Maxn] == 0);
}

void Set(int r,int c,int val){
    row[r]  = val;
    diag1[r + c] = val;
    diag2[r - c + Maxn] = val;
}

void go(int c){
    if (c == 8){
        ans++;
        return;
    }

    vector<int> R;
    for (int r = 0; r < 8; r++)
        if (a[r][c] == '.') R.eb(r);

    if (R.empty()) go(c + 1);
    else {
        for (int r: R)
            if (valid(r,c)){
                Set(r,c,1);
                go(c + 1);
                Set(r,c,0);
            }

    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    a.resize(8,vector<char> (8));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) cin >> a[i][j];
    
    go(0);
    cout << ans;
    return 0;
}