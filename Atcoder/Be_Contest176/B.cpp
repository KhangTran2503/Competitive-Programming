#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int r = 0;
    for (char x: s) 
        r = (r + x - '0') % 9;
    if (r == 0) cout << "Yes";
    else cout << "No";
    return 0;
}
