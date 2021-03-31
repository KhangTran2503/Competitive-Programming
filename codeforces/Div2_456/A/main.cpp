#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll A,B,x,y,z;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>A>>B;
    cin>>x>>y>>z;
    x=2*x+y;
    z=3*z+y;
    ll res=max(x-A,0LL)+max(z-B,0LL);
    cout<<res;
    return 0;
}
