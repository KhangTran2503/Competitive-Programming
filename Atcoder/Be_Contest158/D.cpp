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
string s;
int state = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    int q;
    vector<vector<char>> add(2);
    cin >> q;
    while (q--){
        int t;
        cin >> t;
        if (t == 1) state ^= 1;
        else {
            int f; char c;
            cin >> f >> c;
            f--;
            add[state^f].eb(c);
        }
    }

    string t = "";
    //if (state) reverse(all(s));
    
	for(int i=(int)add[0].size()-1; ~i; --i)
		t+=add[0][i];
	
    t+=s;
	for(char c : add[1])
		t+=c;
	if(state)
		reverse(t.begin(), t.end());

    cout << t;
    return 0;
}