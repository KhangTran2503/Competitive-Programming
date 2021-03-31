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
int n, m;

bool is_pal(string s){
    int len = s.size();
    for (int i = 0; i < len; i++)
        if (s[i] != s[len - i - 1]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n  >> m;
    vector<string> a(n);
    vector<pair<string,int>> pal;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (is_pal(a[i])) pal.push_back({a[i],i});
        //sort(all(a[i]));
    }
    vector<int> used(n);
    string lef = "", mid = "", rig = "";
    for (int i = 0; i < n; i++)
        if (!used[i]){
            bool ok = false;
            for (int j = i + 1; j < n; j++){
                string t = a[j];
                reverse(all(t)); 
                if (!used[j] && t == a[i]){
                    ok = true;
                    used[j] = true;
                    rig += a[j];
                    break;
                }
            }    
            if (ok) {
                used[i] = true;
                lef = a[i] + lef;
            }
        }
    for (auto x: pal){
        string y = x.first;
        if (!used[x.second] && y.size() > mid.size()) mid = y;
    }

    string ans = lef + mid + rig;
    cout << ans.size() << '\n';
    cout << ans;
    return 0;
} 