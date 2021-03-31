#include <iostream>
#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x); i<=(y);i++)
#define Name "B"
using namespace std;
int n,a,b,res=10,_n,sl;
int c[7],d[7],ans[7];

void check()
{
   int su=0,dem=0;
   fto(i,1,6)
     if (su+ans[i]>n)
     {
         su=ans[i];
         dem++;
     }
     else su+=ans[i];
   dem++;
   res=min(res,dem);
}
//=======================
void Try(int i)
{
    fto(j,1,6)
      if (d[j])
      {
          d[j]=0;
          ans[i]=c[j];
          if (i==6) check();
          else Try(i+1);
          d[j]=1;
      }
}

//=========================
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n;
    cin>>a;
    fto(i,1,4) c[i]=a;
    cin>>b;
    fto(i,5,6) c[i]=b;
    memset(d,1,sizeof(d));
    Try(1);//sinh hoan vi
    cout<<res;
    return 0;
}
