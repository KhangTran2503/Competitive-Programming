#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    cin >> s;
    int n = s.size();
    int diff = 0;
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n - i - 1]) diff++;
    cout << diff;    
    return 0;
}