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
using namespace std;
ll n;
int k;
int diff;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    int sbit = bitcount(n);
    if (sbit > k){
        cout << "NO";
        return 0;
    }

    //cout << "YES" <<'\n';
    priority_queue<ll> ans;
    for (int i = 0; i < 32; i++)
        if (n & (ll)(1<<i)) ans.push((ll)(1<<i));

    //for (int x: ans) cout << x <<' ';
    //cout << '\n';
    while (ans.size () < k && ans.top() > 1){
        ll x = ans.top();
        ans.pop();
        ans.push(x/2);
        ans.push(x/2);
    }

    if (ans.size() != k) cout << "NO";
    else {
        cout << "YES" <<'\n';
        while (!ans.empty()){
            cout << ans.top() <<' ';
            ans.pop();
        }
    }
    return 0;
}
