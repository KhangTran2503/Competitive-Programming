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
typedef tuple<int,int,int> tup;
const int INF = int(1e9);
int M;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> M;
    vector<tup> team(1001);
    set<int> tt;
    for (int i = 0; i < M; i++){
        int t1, t2, x, y;
        cin >> t1 >> t2 >> x >> y;
        int a1,b1,c1,a2,b2,c2;
        tie(a1,b1,c1) = team[t1];
        tie(a2,b2,c2) = team[t2];
        if (x > y){
            a1+= 3;
            b1 += x;
            c1 += y;
            b2 += y;
            c2 += x;
        }
        else if (y > x){
            a2 += 3;
            b1 += x;
            c1 += y;
            b2 += y;
            c2 += x;
        }
        else{
            a1++;
            b1++;
            b1 += x;
            c1 += y;
            b2 += y;
            c2 += x;
        }
        
        team[t1] = make_tuple(a1,b1,c1);
        team[t2] = make_tuple(a2,b2,c2);
        tt.insert(t1);
        tt.insert(t2);
    }

    vector<tuple<int,int,int,int>> scr;
    for (int x: tt){
        int a, b , c;
        tie(a,b,c) = team[x];
        scr.pb(make_tuple(a,b - c,b,-x));
    }
    sort(all(scr));
    for (int i = 0; i < sz(scr); i++){
        int a,b,c,d;
        tie(a,b,c,d) = scr[i];
        cout << -d << ' ' << b << ' ' << c << ' ' << a << '\n';
    }
    return 0;
}