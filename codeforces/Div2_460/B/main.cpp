#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k;

bool check(int u)
{
    int su=0;
    while (u>0)
    {
       su+=(u%10);
       u/=10;
    }
    return (su==10);
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>k;
    int dem=0;
    for(int i=19;; i++)
      if (check(i))
      {
          dem++;
          if (dem==k)
          {
              cout<<i;
              break;
          }
      }
    return 0;
}
