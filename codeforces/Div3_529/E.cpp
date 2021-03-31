/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector
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
string s;
int n;
int pre[N], suf[N];
bool ktpre[N], ktsuf[N];

/// bai co day ngoac thi +1,-1
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s;
    ktpre[0] = 1;
    for (int i = 0; i < n; i++){
        pre[i+1] = pre[i] + ((s[i] == '(') ? 1:-1); // tinh tong tien to
        bool kt = (pre[i+1] >= 0); // neu ma du dau '(' thi danh dau vi tr
        ktpre[i+1] = ktpre[i] & kt; //neu day 1->i xuat co nhieu dau ')'
                                    // day ko can bang
    }

    ktsuf[n+1] = 1; // chay nguoc lai
    for (int i = n-1; i >= 0; i--){
        suf[i+1] = suf[i+2] + ((s[i] == ')') ? 1:-1);
        bool kt = (suf[i+1] >= 0); /// neu ma du dau ')' thi danh dau vi tri
        ktsuf[i+1] = ktsuf[i+2] & kt;  //neu day n->i xuat co nhieu dau '('
                                    // day ko can bang
    }

    /// => do de kiem tra co du 1 dau hay k
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (ktpre[i-1] && ktsuf[i+1]){
            if (s[i-1] == '('){
                if (pre[i-1] - suf[i+1] - 1 == 0) ans++;/// tinh so luong khi
            }                                           /// khi thay doi
            else{
                if (pre[i-1] - suf[i+1] + 1 == 0) ans++;
            }
        }
    cout << ans;
    return 0;
}
