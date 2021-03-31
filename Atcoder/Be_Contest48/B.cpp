#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) cout << s[i] << t[i];

    return 0;
}