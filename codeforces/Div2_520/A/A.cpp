#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[105],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int res=0;
    for (int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
           if (a[j]-a[i]<=j-i) res=max(res,j-i-1);
    if (a[1]==1)
        for(int i=2; i<=n; i++)
           if (a[i]-1==i-1) res=max(res,i-1);
    if (a[n]==1000)
        for (int i=n-1; i>=1; i--)
           if (a[n]-a[i]==n-i) res=max(res,n-i);
    cout<<res;
    return 0;
}
