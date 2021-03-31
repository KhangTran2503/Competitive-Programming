#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,dem;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        if (x<0) dem++;
    }
    if (dem<=1 || dem>=n-1) cout<<"Yes";
    else cout<<"No";
    return 0;
}
