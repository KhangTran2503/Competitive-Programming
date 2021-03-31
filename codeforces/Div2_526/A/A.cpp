#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[105];
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];


    int ans=int(1e9);
    for (int i=1; i<=n; i++){
        int tmp=0;
        for(int j=1; j<=n; j++)
            tmp+=(abs(j-i)+abs(i-1)+abs(j-1))*a[j];
        ans=min(ans,tmp);
    }
    cout<<2*ans;

    return 0;
}
