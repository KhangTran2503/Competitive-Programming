#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x % 14 >= 1 && x % 14 < 7) cout << "YES ";
    }
    return 0;
}