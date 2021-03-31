#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[1005],dd[1005],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    memset(dd,false,sizeof(dd));
    f[1]=1; f[2]=1;
    dd[1]=true; dd[2]=true;
    for(int i=3; ; i++)
    {
        f[i]=f[i-1]+f[i-2];
        dd[f[i]]=true;
        if (f[i]>=n) break;
    }
    for(int i=1; i<=n; i++)
        if (dd[i]) cout<<'O';
        else cout<<'o';
    return 0;
}
