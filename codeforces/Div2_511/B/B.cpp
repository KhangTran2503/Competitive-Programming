#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    int res=0;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        res=max(res,x+y);
    }
    cout<<res;
    return 0;
}
