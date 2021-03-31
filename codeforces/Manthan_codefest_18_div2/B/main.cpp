#include <iostream>
#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef long long ll;
int a[N],n,s;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>s;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    ll res=0;
    for(int i=(n+1)/2; i<=n; i++)
        if (a[i]<s) res+=ll(abs(a[i]-s));
        else break;
    for(int i=1; i<=(n+1)/2; i++)
        if (a[i]>s) res+=ll(abs(a[i]-s));
    cout<<res;
    return 0;
}
