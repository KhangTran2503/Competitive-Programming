#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    
    int ans = 0;
    vector<int> l(n);
    vector<int> r(n);

    l[0] = 1;
    for (int i = 1; i < n; i++){
        l[i] = (a[i] > a[i - 1]) ? l[i - 1] + 1: 1;
        ans = max(ans,l[i]);
    }

    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        r[i] = (a[i] < a[i + 1]) ? r[i + 1] + 1: 1;

    for (int i = 1; i < n - 1; i ++)
        if (a[i - 1] < a[i + 1])
            ans = max(ans,l[i - 1] + r[i + 1]);
    cout << ans;            
    return 0;
}