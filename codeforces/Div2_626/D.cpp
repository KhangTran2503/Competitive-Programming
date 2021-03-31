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
vector<int> a;
vi bit1, bit0;
int n;

int isbit(int pos){ // check pos is bit 1
    bit0.clear();
    bit1.clear();
    int mask = (1 << pos) - 1;
    int posval = mask + 1;

    for (int x: a)
        if (getbit(x,pos)) bit1.eb(x & mask);
        else bit0.eb(x & mask);
    
    sort(all(bit0));
    sort(all(bit1));
    // if bit(pos) of u = 1 and bit(pos) of v = 1 then bit(pos) of u + v = 0
    // Check (u & mask) + (v & mask) >= (1 << pos) => bit(pos) of u + v = 1

    int cnt = 0;
    int temp = 0;
    for (int i = 0; i < sz(bit1); i++){
        int id = lower_bound(bit1.begin() + i + 1,bit1.end(),posval - bit1[i]) - bit1.begin();
        temp += (sz(bit1) - id);
    }

    cnt += (temp & 1);
    // if bit(pos) of u = 0 and bit(pos) of v = 0 then bit(pos) of u + v = 0
    // Check (u & mask) + (v & mask) >= (1 << pos) => bit(pos) of u + v = 1

    temp = 0;
    for (int i = 0; i < sz(bit0); i++){
        int id = lower_bound(bit0.begin() + i + 1,bit0.end(),posval - bit0[i]) - bit0.begin();
        temp += (sz(bit0) - id);
    }

    cnt += (temp & 1);

    // if bit(pos) of u = 0 and bit(pos) of v = 1 then bit(pos) of u + v = 1
    // Check (u & mask) + (v & mask) < (1 << pos) => bit(pos) of u + v = 1
    temp = 0;
    for (int x: bit1){
        int id = lower_bound(all(bit0),posval - x) - bit0.begin();
        temp += id;
    }

    cnt += (temp & 1);

    return (cnt & 1);



}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &x: a) cin >> x;

    int ans = 0;
    for (int pos = 0; pos < 25; pos++)
        if (isbit(pos)) ans ^= (1 << pos);

    cout << ans; 
    return 0;
}