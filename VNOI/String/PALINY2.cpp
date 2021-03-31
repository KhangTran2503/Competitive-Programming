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
using namespace std;
const db Pi = acos(-1);
int n;
string s;
int ans = 0;

/// Manacher

void calc1(){
    vector<int> d1(n);
    int L = -1, R = -1;
    for (int i = 0; i < n; i++){
        int k = (i > R) ? 1 : min(R-i,d1[L+R-i]);
        while (i - k >= 0 && i+k < n && s[i-k] == s[i+k]) k++;
        ans = max(ans,2*k-1);
        d1[i] = k--;
        if (i + k > R){
            R = i + k;
            L = i - k;
        }
    }

}

void calc2(){
    vector<int> d2(n);
    int L = -1, R = -1;
    for (int i = 0; i < n; i++){
        int k = (i > R) ? 0 : min(R-i+1,d2[L+R-i+1]);
        while (i-k-1 >= 0 && i+k < n && s[i+k] == s[i-k-1]) k++;
        ans = max(ans, 2*k);
        d2[i] = k--;
        if (i+k > R){
            L = i - k -1;
            R = i + k;
        }

    }
    
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s;
    calc1();
    calc2();
    cout << ans;
    return 0;
}
