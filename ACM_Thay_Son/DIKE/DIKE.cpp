#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

bool check(ll k)
{
    ll tmp=(k*(k+1))/2;

    if (tmp%3==0) tmp=(tmp/3)*(k+5);
    else tmp=tmp*((k+5)/3);
    return (tmp<=n+1);
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    int l=0,r=2000000,res=0;
    while(l<=r)
    {
      int mid=(l+r)>>1;
      if (check((ll)mid))
      {
          res=mid;
          l=mid+1;
      }
      else r=mid-1;
    }
    cout<<res;
    return 0;
}
