#include <bits/stdc++.h>
using namespace std;
int n, t;

//greedy 
// take gold minimun
// take silver minimun
// 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        int nn = n/2;
        if (p[nn + 1] == p[nn]) 
            while (p[nn] == p[n/2]) nn--;

        int g = 0, s = 0, b = 0;
        g = 1;
        while (g < nn && p[g] == p[g + 1]) g++;
        s = g + 1;
        while (s + g < nn && p[s + g] == p[s + g + 1]) s++;
        b = nn - g - s;
        if (b <= g) cout << "0 0 0\n";
        else cout << g << ' ' << s << ' ' << b << '\n';

        
    }
    return 0;
} 