#include<bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n;
/// |i - j|*k <= min(a[i],a[j])
/// thu tat ca TH voi a[i] neu a[i] la min thi cx dung


int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = oo;
    for (int i = 0; i < n; i++){
        if (i > 0) ans = min(ans, a[i]/i);
        if (i < n - 1) ans = min(ans, a[i]/(n - 1 - i));
    }
    cout << ans;
    return 0;
}
