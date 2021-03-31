#include <iostream>
#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int d[N];
int n,last;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        d[x]=i;
    }
    last=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (d[x]<=last) cout<<0<<' ';
        else
        {
            cout<<d[x]-last<<' ';
            last=d[x];
        }
    }
    return 0;
}

