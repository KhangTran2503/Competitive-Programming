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
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 5*int(1e4)+5
using namespace std;
const db Pi = acos(-1);
char s[N];
int n;
ll Pow[N], HashL[N] ={0}, HashR[N]={0};

void Init(){
    Pow[0] = 1;
    for (int i = 1; i <= n; i++) Pow[i] = Pow[i-1] * 331;
    for (int i = 1; i <= n; i++) HashL[i] = HashL[i-1] * 331 + s[i];
    for (int i = n; i >= 1; i--) HashR[i] = HashR[i+1] * 331 + s[i];
}

ll gethashL(int l,int r){
    return HashL[r] - HashL[l-1]*Pow[r-l+1];
}
ll gethashR(int l,int r){
    return HashR[l] - HashR[r+1]*Pow[r-l+1];
}

bool check(int len){
    for (int i = 1; i <= n - len + 1; i++)
        if (gethashL(i,i+len-1) == gethashR(i,i+len-1)) return true;
    return false;
}
/// chat np xau xau doi xung
/// chia 2 TH chan le
int solve(int u){
    int l = 0, r = n/2 ;
    int res = 0;
    while (l <= r){
        int mid = (l+r) >> 1;
        if (2*mid + u <= n && check(2*mid + u)){
            res = 2*mid + u;
            l = mid+1;
        }
        else r = mid - 1;
    }
    return res;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    Init();
    cout << max(solve(0),solve(1));
    return 0;
}
