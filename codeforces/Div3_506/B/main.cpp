#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int a[N],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;

    for(int i=1; i<=n; i++) cin>>a[i];

    int res=0;
    if (n==1) cout<<1;
    else
    {
        for(int i=1; i<n; )
          {
             int j=i+1;
            while (j<=n && 2*a[j-1]>=a[j]) j++;
            res=max(res,j-i);
             i=j;
          }
       cout<<res;
     }
    return 0;
}
