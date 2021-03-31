#include<bits/stdc++.h>
using namespace std;
int a[105], n;


int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)  cin >> a[i];

    sort(a+1,a+1+n);
    int res = 0;
    for(int i=1; i<n; i+=2)
        res+=abs(a[i+1]-a[i]);

    cout << res;
    return 0;
}
