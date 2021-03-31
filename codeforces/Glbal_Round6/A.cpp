#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int zero = 0;
        int sum = 0;
        int even = 0;
        for (int i = 0; i < s.size(); i++){
            sum = (sum + s[i] - '0') % 3;
            zero += (s[i] == '0');
            even += ((s[i] - '0') % 2 == 0);
        }
        zero = min(zero,1);
        if (zero > 0 && sum == 0 && even - zero > 0) cout << "red\n";
        else cout << "cyan\n";    
    }
    return 0;
}