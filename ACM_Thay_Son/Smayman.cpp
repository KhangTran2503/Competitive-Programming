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
int n, T;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n;
        deque<int> t;
        int mem = 0;
        for (int i = 1; i <= n; i++){
            t.push_front((mem + i)%10);
            mem = (i+mem) / 10;
        }
        for (int i = n - 1; i >= 1; i--){
            t.push_front((mem+i) % 10);
            mem = (i + mem) / 10;
        }
        //cout << mem << '\n';
        vector<int> num;
        while (mem > 0){
            num.push_back(mem%10);
            mem /= 10;

        }
        for (int i = num.size()-1; i >= 0; i--) t.push_front(num[i]);
        while (!t.empty()){
            cout << t.front();
            t.pop_front();
        }
        cout << '\n';


    }

    return 0;
}
