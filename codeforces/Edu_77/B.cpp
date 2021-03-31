#include <bits/stdc++.h>
using namespace std;
int T;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        if (a + a < b || (a + b) % 3 ) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}