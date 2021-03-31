#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    cin >> n;
    cin >> s;
    int ans = 0;
    for (int  i = 0; i < s.size() - 2; i++)
        if (s.substr(i,3) == "ABC") ans++;
    cout << ans;
    return 0;
}