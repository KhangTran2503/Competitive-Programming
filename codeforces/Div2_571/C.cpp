#include <bits/stdc++.h>
using namespace std;
string a, b;

/// Nhan xet: neu b <> c bit i thi la a ^ b , ma cha thi cac bit xor nhau = 0
/// tao mang tien to xor tren bang a
/// Sau do lay doan do dai m , Xor[i]^Xor[i - m] ^ Xorb kiem tra co la chan hay k
int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> a;
    cin >> b;
    int n = a.size();
    int m = b.size();
    vector<int> Xor(n + 1);
    for (int i = 1; i <= n; i++)
        Xor[i] = Xor[i - 1] ^ (a[i - 1] - '0');
    int Xorb = 0;
    for (int i = 0; i < m; i++) Xorb ^= (b[i] - '0');
    int ans = 0;
    for (int i = m; i <= n; i++)
        if (Xor[i] ^ Xor[i - m] ^ Xorb == 0) ans ++;
    cout << ans;
    return 0;
}
