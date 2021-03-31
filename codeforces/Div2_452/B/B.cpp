#include <iostream>
#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x); i<=(y); i++)
#define Name "B"
using namespace std;
int day[50]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int n,a[26];

void check()
{
    fto(i,25,48)
      day[i]=day[i-24];
    fto(i,1,48-n+1)
      {
          bool ok=true;
          fto(j,1,n)
            if (a[j]!=day[i+j-1])
            {
                ok=false;
                break;
            }
          if (ok)
          {
              cout<<"YES";
              exit(0);
          }
      }
}

//==============================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n;
    fto(i,1,n) cin>>a[i];
    check();
    day[2]=28;
    day[14]=29;
    check();
    day[2]=29;
    day[14]=28;
    check();
    cout<<"NO";
    return 0;
}
