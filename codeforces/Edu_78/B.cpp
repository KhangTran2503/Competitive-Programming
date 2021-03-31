#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        ll a, b;
        cin >> a >> b;
        ll delta = 0;
        while (1){
            ll s = delta*(delta + 1)/2;
            s += (a + b);
            if (s % 2 == 0 && s/2 >= max(a,b)){
                cout << delta << '\n';
                break;
            }
            delta++;
        }
    }
    return 0;
}