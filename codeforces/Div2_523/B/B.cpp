#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int n,m;
ll s=0;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
            cin>>a[i];
            s+=(ll)a[i];
    }
    sort(a.rbegin(),a.rend());
    ll res=0;
    for (int i=0; i<=n; ){
        int j=i;
        while (j<=n && a[j]==a[i]) j++;
        if (j>n) break;
        int h=a[i]-a[j];
        int d=j-i;
        if (h>=d) res+=(ll)h;
        else res+=(ll)d;
        i=j;

    }
    cout<<s-res;
    return 0;
}
