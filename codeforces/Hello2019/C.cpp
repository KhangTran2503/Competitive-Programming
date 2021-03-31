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
#define N int(1e6)+5
using namespace std;
int d1[N]={0}, d2[N]={0},d0;
int res = 0;
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int tmp1 = 0;
        bool ok1 = true;
        for (int j = 0; j < s.size(); j++){
                if (s[j] == '(') tmp1++;
                else tmp1--;
                if (tmp1 < 0) ok1 = false;
        }

        int tmp2 = 0;
        bool ok2 = true;
        for (int j = s.size()-1; j >= 0; j--){
                if (s[j] == ')') tmp2++;
                else tmp2--;
                if (tmp2 < 0) ok2 = false;
            }
        if (ok1 || ok2){
            if (tmp1 == 0 || tmp2 == 0) d0++;
            else{
                if (ok1) d1[tmp1]++;
                else d2[tmp2]++;
            }
        }
    }

    res = (d0/2);
    for (int i = 1; i < N; i++)
        res += min(d1[i],d2[i]);
    cout <<res;
    return 0;
}
