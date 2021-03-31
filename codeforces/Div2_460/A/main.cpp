#include <iostream>
#include <bits/stdc++.h>
#define db double
using namespace std;
db res;
int n,m;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    res=1e18;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        cin>>a>>b;
        res=min(res,(db)a/(db)b);
    }
    res=res*(db)m;
    cout<<fixed<<setprecision(12)<<res;
    return 0;
}
