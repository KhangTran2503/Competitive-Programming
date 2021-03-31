#include <bits/stdc++.h>
using namespace std;
int A1, A2, A3;
int main(){
    cin >> A1 >> A2 >> A3;
    if (A1 + A2 + A3 > 21) cout << "bust";
    else cout << "win"; 
    return 0;
}