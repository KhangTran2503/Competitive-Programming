#include <iostream>
#include <bits/stdc++.h>
#define Name "A"
#define N 105
#define fto(i,x,y) for(int i=(x); i<=(y); i++)
#define fdto(i,x,y) for(int i=(x); i>=(y); i--)
#define oo int(1e9)
using namespace std;
int a[N],f[N],n,d;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n>>d;
    fto(i,1,n)
    {
        char c;
        cin>>c;
        if (c=='1') a[i]=1;
        else a[i]=0;
        f[i]=oo;
    }
    f[1]=0;
    fto(i,2,n)
      if (a[i]==1)
       fto(t,1,d)
         {
             if (i-t<=0) break;
             if  (a[i-t]==1) f[i]=min(f[i],f[i-t]+1);
         }
    if (f[n]!=oo) cout<<f[n];
    else cout<<-1;
    return 0;
}
