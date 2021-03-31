#include <bits/stdc++.h>
#define N int(1e6)+5
using namespace std;
string a,b;
int n;
int c[N];

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    cin>>a;
    cin>>b;
    for (int i=1; i<=n; i++)
        c[i]=a[i-1]-b[i-1];///-1,0,1 la chi su khac nhau


     int res=0;
    for(int i=1; i<=n; i++)
      if (c[i-1]!=0)
      {
          if (c[i-1]+c[i]==0)///neu hai so can doi cheo nhau
          {
              res++;
              c[i-1]=c[i]=0;
          }
      }
    for(int i=1; i<=n; i++)
        if (c[i]) res++;
    cout<<res;


    return 0;
}
