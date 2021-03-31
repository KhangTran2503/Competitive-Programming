#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ans = n + 1;
    int cur = 1;
    for (int x: a)
        if (x == cur){
            ans = cur;
            cur++;
        }
    cout << n - ans;    
    return 0;
}