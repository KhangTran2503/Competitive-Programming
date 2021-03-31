#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, K;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A >> B >> K;
    if (K <= A) cout << A - K << ' ' << B;
    else if (K <= A + B) cout << 0 << ' ' << (A + B) - K ;
    else cout << 0 << ' ' << 0;
    return 0;
}