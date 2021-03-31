#include <iostream>
#include<bits/stdc++.h>
#define N int(1e5)+5
#define ll long long
using namespace std;
ll a[N],n;
int k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    if (n==0)
    {
        cout<<1<<' '<<0;
        return 0;
    }
    for(int i=1; i<=k; i++) cin>>a[i];
    ll res=0,r1=1,r2=0;
    for(int i=1; i<=k; i++)
      if (n>=a[i])
      {
          ll tg=n/(ll)(a[i]);
          if (res<tg*(ll)a[i])
          {
              res=tg*(ll)a[i];
              r1=i;
              r2=tg;
          }
      }
    cout<<r1<<' '<<r2;
    return 0;
}
