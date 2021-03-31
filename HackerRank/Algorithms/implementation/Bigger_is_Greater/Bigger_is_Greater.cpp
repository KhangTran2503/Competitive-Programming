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

string Process(string s){
    int n = s.size();
    for (int i = n-1 ; i > 0 ; i--)
        if (s[i] > s[i-1]){
            for (int j = n-1; j >=i; j--)
                if (s[j] > s[i-1]){
                    swap(s[j],s[i-1]);
                    break;
                }
            string t ="";
            for (int j = 0; j < i; j++) t = t + s[j];
            for (int j = n-1 ; j >=i ; j--) t = t + s[j];
            return t;

        }
    return "no answer";    
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        cout << Process(s) << '\n';
    }

    return 0;
}
