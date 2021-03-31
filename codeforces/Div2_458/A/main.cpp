#include <iostream>
#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n,x;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    int res=-oo;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if (x<0) res=max(res,x);
        else
        {
            int t=sqrt(x);
            if (t*t!=x) res=max(res,x);
        }
    }
    cout<<res;
    return 0;
}
