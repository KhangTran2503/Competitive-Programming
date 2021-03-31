#include <bits/stdc++.h>
#define N 2005
using namespace std;
int64_t a[N],b[N],Mina[N],Minb[N],X;
int n,m,res;


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

     for(int i=1; i<=m; i++)
    {
        cin>>b[i];
        b[i]+=b[i-1];
    }


    for(int i=1; i<=n; i++) Mina[i]=int64_t(1e18);
    for(int i=0; i<n; i++)
      for(int j=i+1; j<=n; j++)
         Mina[j-i]=min(Mina[j-i],a[j]-a[i]);


    for(int i=1; i<=m; i++) Minb[i]=int64_t(1e18);
    for(int i=0; i<m; i++)
      for(int j=i+1; j<=m; j++)
         Minb[j-i]=min(Minb[j-i],b[j]-b[i]);

    cin>>X;
    res=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
           if (Mina[i]*Minb[j]<=X) res=max(res,i*j);
    cout<<res;

}
