#include <iostream>
#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int x[25],t;

int solve(int a[],int n)
{
   int Minx=oo, Maxx=-oo;
   for(int i=1; i<=n; i++)
   {
       Minx=min(Minx,a[i]);
       Maxx=max(Maxx,a[i]);
   }
   return (Maxx-Minx)*2;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) cin>>x[i];
        cout<<solve(x,n)<<'\n';
    }
    return 0;
}
