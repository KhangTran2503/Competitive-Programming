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
string s;
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    cin >> s;
    //n = s.size();
    if (s[n - 1] == 'x'){
        s.erase(n - 1,1);
        reverse(all(s));
        int sum = 0;
        for (int i = 0; i < n - 1; i++){
            int x = s[i] - '0';
            if (i & 1 == 0){
                x *= 2;
                if (x > 10) sum += (x % 10) + (x / 10);
                else sum += x;
            }
            else sum += x;
        }
        cout << (sum * 9) % 10;
    }
    else {
        int id = s.find('x');
        int last = s[n - 1] - '0';
        s.erase(n - 1,1);
        reverse(all(s));
        int sum = 0;
        if (id & 1){
            for (int i = 0; i < n - 1; i++)
            if (s[i] != 'x'){
                int x = s[i] - '0';
                if (i & 1 == 0){
                    x *= 2;
                    if (x > 10) sum += (x % 10) + (x / 10);
                    else sum += x;
                }
                else sum += x;
            }
            for (int i = 0; i < 10; i++)
                if (((sum + i) % 9 - last) % 10 == 0){
                    cout << i;
                    return 0;
                }
        }
        else{
            for (int i = 0; i < n - 1; i++)
            if (s[i] != 'x'){
                int x = s[i] - '0';
                if (i & 1 == 0){
                    x *= 2;
                    if (x > 10) sum += (x % 10) + (x / 10);
                    else sum += x;
                }
                else sum += x;
            }
            for (int i = 0; i < 10; i++){
                int xx = 2 * i;
                int t = 0;
                if (xx > 10) t = (xx/ 10) + (xx % 10);
                else t = xx;
                if (((sum + t) % 9 - last) % 10 == 0){
                    cout << i;
                    return 0;
                }
            }
        }
    }

    return 0;
}
