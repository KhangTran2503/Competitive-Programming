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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int n;
string ans;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = n - 1;
    int cur  = 0;
    while (1){
        if (max(a[left], a[right]) <= cur) break;

        if (a[left] == a[right]){
            int l = left + 1;
            while (l <= right && a[l] > a[l - 1]) l++;
            int r = right - 1;
            while (r >= left && a[r] > a[r + 1]) r--;
            if (l - left > right - r)
                for (int i = 0; i < l - left; i++) ans.pb('L');
            else
                for (int i = 0; i < right - r; i++) ans.pb('R');
            break;
        }

        int Min = min(a[left], a[right]);

        if (Min > cur){
            if (a[left] > a[right]){
                ans.pb('R');
                cur = a[right];
                right --;
            }
            else{
                ans.pb('L');
                cur = a[left];
                left ++;
            }
        }
        else {
            if (a[left] > a[right]){
                ans.pb('L');
                cur = a[left];
                left ++;
            }
            else{
                ans.pb('R');
                cur = a[right];
                right --;
            }
        }
    }

    cout << sz(ans) << '\n';
    cout << ans;

    return 0;
}
