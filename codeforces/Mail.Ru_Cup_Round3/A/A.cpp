#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,r;
int d[105];
int main()
{
    //cout << "Hello world!" << endl;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>r;
        for(int j=1; j<=r; j++){
            int x;
            cin>>x;
            d[x]++;
        }
    }
    for(int i=1; i<=100; i++)
        if (d[i]==n) cout<<i<<' ';
    return 0;
}
