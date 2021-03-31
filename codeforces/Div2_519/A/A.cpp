#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int n,res,l=0,r,s=0;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        s+=a[i];
        l=max(l,a[i]);
    }
    r=int(1e6);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if (mid*n>2*s)
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;

    }
    cout<<res;

    return 0;
}
