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
int a[25][25];
int cnt[1005];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n*n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (n % 2 == 0){ /// neu n chan thi cac so pai chia het cho 4
        for (int i = 1; i <= 1000; i++)
            if (cnt[i] > 0 && cnt[i] % 4 != 0) {
                cout << "NO";
                return 0;
            }
        int num = 1;
        for (int i = 1; i <= n/2; i++)
            for (int j = 1; j <= n/2; j++){
                while (cnt[num] == 0 && num <= 1000) num++;
                a[i][j] = num;
                a[i][n-j+1] = num;
                a[n-i+1][j] = num;
                a[n-i+1][n-j+1] = num;
                cnt[num] -= 4;

            }

        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
    else { /// neu 4 le thi dien cac o chan chia het cho 4 truoc
        int num = 1;
        for (int i = 1; i <= n/2; i++)
            for (int j = 1; j <= n/2; j++){
                while (cnt[num] < 4 && num <= 1000) num++;
                a[i][j] = num;
                a[i][n-j+1] = num;
                a[n-i+1][j] = num;
                a[n-i+1][n-j+1] = num;
                cnt[num] -= 4;
            }
        num = 1; /// dien cac o chinh giua
        for (int i = 1; i <= n/2; i++){
            while (cnt[num] < 2 && num <= 1000) num ++;
            a[i][n/2 + 1] = a[n + 1 - i][n/2 + 1] = num;
            cnt[num] -= 2;
        }
        num = 1;
        for (int j = 1; j <= n/2; j++){
            while (cnt[num] < 2 && num <= 1000) num++;
            a[n/2 + 1][j] = a[n/2 + 1][n + 1 -j] = num;
            cnt[num] -= 2;
        }
        for (int i = 1; i <= 1000; i++) /// dien o tam
            if (cnt[i] == 1) {
                a[n/2 + 1][n/2 + 1] = i;
                cnt[i]--;
                break;
            }
        for (int i = 1; i <= 1000; i++) /// kiem tra co dung het cac so hay k?
            if (cnt[i] > 0) {
                cout << "NO";
                return 0;
            }

        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
                cout << '\n';
        }
    }
    return 0;
}
