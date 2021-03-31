#include <bits/stdc++.h>
#define N 100005
#define Fi "vao.inp"
#define Fo "ra.out"
using namespace std;
int a[N],n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(Fi,"r",stdin);
    //freopen(Fo,"w",stdout);
    cin>>n;
    int minn=(int)(1e9)+7,id=0,res=n+1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        minn=min(a[i],minn);
    }
    for(int i=1; i<=n; i++)
    if(a[i]==minn)
    {
        if(id!=0)
            res=min(res,i-id);
        id=i;
    }
    cout<<res;

    return 0;
}
