#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>a>>b;
    if (a>b) swap(a,b);
    if (b-a==1) cout<<1;
    else
    {
        int res=int(1e9);
        for(int i=a+1; i<b; i++)
        {
            int ans=0;
            for(int x=a+1; x<=i; x++) ans+=(x-a);
            for(int x=i; x<b; x++) ans+=(b-x);
            res=min(res,ans);
        }
        cout<<res;
    }
    return 0;
}
