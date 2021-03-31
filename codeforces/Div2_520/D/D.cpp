#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    ll res=0;
    for(int i=2; i<=n; i++)
      for(int j=2; i*j<=n; j++)
        res+=4*ll(j);
    cout<<res;
    return 0;
}
