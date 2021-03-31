/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
typedef pair<ii,int> iii;
int T;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<iii> seg(n);
        vector<int> d(n);
        for (int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            seg[i] = iii(ii(l,r),i);
        }
        sort(all(seg));
        int cnt = 1;
        for (int i = 0; i < n; ){
            int j = i;
            cnt = (cnt+1)%2;
            int maxR = seg[i].fir.sec;
            while (j < n && seg[j].fir.fir <= maxR){
                maxR = max(maxR,seg[j].fir.sec);
                d[seg[j].sec] = cnt + 1;
                j++;
            }
            i = j;
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (d[i] != 1) ok = false;
        if (!ok) {
            for(int i = 0; i < n; i++) cout << d[i] << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }

    return 0;
}
