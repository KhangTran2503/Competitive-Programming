#include <iostream>
#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x); i<=(y); i++);
#define Name "B"
using namespace std;
int n,a,b;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
   // freopen(Name".OUT","w",stdout);
    cin>>n>>a>>b;
    if (n%__gcd(a,b)) cout<<"NO";
    else
    {
        bool ok=true;
        for (int i=0; i<=10000000; i++)
        {
            if (a*i<=n)
          {
             if ((n-a*i)%b==0)
             {
                 cout<<"YES"<<'\n';
                 cout<<i<<' '<<(n-a*i)/b;
                 ok=false;
                 break;
             }
           }
           else break;
        }
        if (ok) cout<<"NO";
    }
    return 0;
}
