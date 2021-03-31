#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector
#define fir first
#define sec second
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
string s;
int n;

int main()
{
    cin >> s;
    n = s.size();
    if (n == 1){
        cout << s;
        return 0;
    }
    string t="";
    if (s.size() % 2 == 0){

        for (int i = 0; i<s.size()/2; i++){
            if (n-i-1!=i){
                t = t+s[n-i-1];
                t = t+s[i];
                //cout << s[i] <<' ' << s[n-i-1]<<' ';
            }
            else t= t+s[i];
        }
    }
    else {
        for (int i = 0; i<=s.size()/2; i++){
            if (n-i-1!=i){
                t= t+s[i];
                t= t+s[n-i-1];
                //cout << s[i] <<' ';
            }
            else t=t+s[i];
        }

    }
    reverse(t.begin(),t.end());
    cout << t;
    return 0;
}
