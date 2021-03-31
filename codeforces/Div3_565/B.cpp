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


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x % 3 == 0) cnt0++;
            if (x % 3 == 1) cnt1++;
            if (x % 3 == 2) cnt2 ++;
        }
        int ans = 0;
        ans += cnt0;
        ans += min(cnt2,cnt1);
        int tmp  = min(cnt1,cnt2);
        cnt2 -= tmp;
        cnt1 -= tmp;
        tmp = min(cnt2/2,cnt1);
        ans += tmp;
        cnt2 -= 2*tmp;
        cnt1 -= tmp;
        ans += cnt2/3;
        ans += cnt1/3;
        cout << ans << '\n';
    }

    return 0;
}
