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
#define N 2*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
map<char,ii> d;
ii dir[N];
int n, xs, ys;

void init(){
    d['U'] = ii(0,1);
    d['D'] = ii(0,-1);
    d['L'] = ii(-1,0);
    d['R'] = ii(1,0);
}
/// gia su Robot dung yen va ko thuc hien lenh i -> i + len - 1
/// xem thu so buoc con lai co <= len hay k
// va co do dai quay lai dc
bool check(int len){
    for (int i = 1; i <= n - len + 1; i++){
        int u = dir[i-1].fir + dir[n].fir - dir[i + len - 1].fir;
        int v = dir[i-1].sec + dir[n].sec - dir[i + len - 1].sec;
        int move = abs(xs - u) + abs (ys - v);
        if (move <= len && (len - move) % 2 == 0) return true;
    }
    return false;

}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        dir[i] = ii( dir[i-1].fir + d[x].fir , dir[i-1].sec + d[x].sec);
    }
    cin >> xs >> ys;

    //for (int i = 1; i <= n; i++) cout << dir[i].fir << ' ' << dir[i].sec << '\n';
    if (dir[n].fir == xs && dir[n].sec == ys){
        cout << 0;
        return 0;
    }

    int l = 1, r = n;
    int ans = -1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';

    return 0;
}
