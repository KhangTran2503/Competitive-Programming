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
vector<db> a;

db f(db x){
    
    db sumpos = a[0] - x; // tong duong
    db sumne = a[0] - x;  // tong am
    db ans = max(sumpos,-sumne);
    for (int i = 1; i < n; i++){
        if (sumpos <= 0) sumpos = (a[i] - x);
        else sumpos += (a[i] - x);

        if (sumne >= 0) sumne = (a[i] - x);
        else sumne += (a[i] - x);
        ans = max(ans,sumpos);
        ans = max(ans,-sumne);
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (db &i: a) cin >> i;
    
    db lef = -10000, rig = 10000;
    db ans = 1e9;
    for (int Loop = 0; Loop < 100; Loop++){
        db x1 = (2*lef + rig)/3;
        db x2 = (lef + 2*rig)/3;
        if (f(x1) < f(x2)) rig = x2;
        else lef = x1;
    }

    cout << prec(7) << f(lef);
    return 0;
}