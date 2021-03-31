#include <bits/stdc++.h>
#define N 200
using namespace std;
int n,a,b;
int get(int u,int v)
{
    if(v<=0 || u<=0) return 0;
    return min(a/u,b/v);
}
int main()
{
    int res=0;
    cin>>n>>a>>b;
    for(int i=1; i<=min(a,n); i++)
        res=max(res,get(i,n-i));
    cout<<res;
    return 0;
}
