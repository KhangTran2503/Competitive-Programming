#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int h, m;
        cin >> h >> m;
        cout << 24*60 - (60*h + m) << '\n';
    }
    return 0;
}