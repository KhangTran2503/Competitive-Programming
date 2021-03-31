#include <bits/stdc++.h>
using namespace std;
int r, c;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0;
        return 0;
    }    
    if (r == 1){
        for (int i = 2; i <= c + 1; i++) cout << i << ' ';
        return 0;
    }   
    if (c == 1){
        for (int i = 2; i <= r + 1; i++) cout << i << '\n';
        return 0;
    }
        
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++) cout << i*(j + r) << ' ';
        cout << '\n';
    }
    
    return 0;
}