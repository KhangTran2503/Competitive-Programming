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
string s;
int n;

void LisMax(){
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;

    for (int i = 0; i < s.size(); )
        if (s[i] == '>'){
            int j = i;
            while (j < s.size() && s[j] == '>') j++;
            reverse(a.begin() + i,a.begin() + j + 1);
            //cout << i << ' ' << j << '\n';
            i = j;
        }
        else i++;
    for (int x: a) cout << x << ' ';
    cout << '\n';
}

void LisMin(){
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = n - i;

    for (int i = 0; i < s.size(); ){
        if (s[i] == '<'){
            int j = i;
            while (j < s.size() && s[j] == '<') j++;
            reverse(a.begin() + i,a.begin() + j + 1);
            i = j;
        }
        else i++;
    }

    for (int x: a) cout << x << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        cin >> s;
        LisMin();
        LisMax();  
    }
    return 0;
}