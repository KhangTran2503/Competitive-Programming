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
string s, t;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> t;
    vector<int> rig(t.size());
    vector<int> lef(t.size());
    int pos = s.size() - 1;
    for (int i = t.size() - 1; i >= 0 ; i--){
        while (pos >= 0 && s[pos] != t[i]) pos--;
        if (pos >= 0){
            rig[i] = pos;
            pos--;
        }
    }

    pos = 0;
    for (int i  = 0; i < t.size(); i++){
        while (pos < s.size() && s[pos] != t[i]) pos++;
        if (pos < s.size()){
            lef[i]  = pos;
            pos++;
        }   
    }


    int ans = 0;
    ans = max(rig[0],int(s.size()) - lef[t.size() - 1] - 1);
    for (int i = 1; i < t.size(); i++)
        ans = max(ans,rig[i] - lef[i - 1] - 1);
    cout << ans;
    return 0;
}