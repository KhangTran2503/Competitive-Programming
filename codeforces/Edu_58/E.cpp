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
priority_queue<int> pq1;
priority_queue<int> pq2;
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char c;
        int x,y;
        cin >> c;
        cin >> x >> y;
        if (c == '+'){
            if (x < y){
                pq1.push(x);
                pq2.push(y);
            }
            else {
                pq1.push(y);
                pq2.push(x);
            }
        }
        else {
            if (pq1.empty()) cout << "NO\n";
            else{
                if ((x >= pq1.top() && y >= pq2.top()) || (y >= pq1.top() && x >= pq2.top())) cout << "YES\n";
                else cout << "NO\n";
            }
        }

    }

    return 0;
}
