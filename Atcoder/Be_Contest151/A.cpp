#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char c;
    cin >> c;
    cout << char((int(c) - 'a' + 1) % 26 + 'a');
    
    return 0;
}