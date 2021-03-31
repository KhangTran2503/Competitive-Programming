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
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 3*int(1e5)+5
using namespace std;
char s[N];
char ans[N];
int n, _n;
int cnt[3] = {0};
deque<int> d[3];


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ans[i] = s[i];
        cnt[s[i] - '0'] ++;
        d[s[i] - '0'].push_back(i);
    }

    int _n = n/3;
    for (int i = 1; i <= n; i++){
        int idx = s[i] - '0';
        if (cnt[idx] > _n){
            for (int j = 0; j < idx; j++){
                while (cnt[j] < _n && cnt[idx] > _n){
                    int id = d[idx].front();
                    d[idx].pop_front();
                    ans[id] = char(j+48);
                    cnt[j] ++ , cnt[idx]--;
                }
            }
        }
    }

    for (int i = n; i >= 1; i--){
        int idx = s[i] - '0';
        if (cnt[idx] > _n){
            for (int j = 2; j > idx; j--){
                while (cnt[j] < _n && cnt[idx] > _n){
                    int id = d[idx].back();
                    d[idx].pop_back();
                    ans[id] = char(j+48);
                    cnt[j] ++ , cnt[idx]--;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) cout << ans[i];
    return 0;
}
