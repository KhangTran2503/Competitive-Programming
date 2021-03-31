#include <bits/stdc++.h>
#define N 20
using namespace std;
string A[N],B[N],a,b;
int n,m,da,db;
int cmp(string u, string v)
{
    int nn=min(u.size(),v.size());
    for(int i=0; i<nn; i++)
    {
        if(u[i]<v[i]) return 1;
        if(u[i]>v[i]) return 0;
    }
    if(u.size()<v.size())
        return 1;
    return 0;
}
int main()
{
    //freopen(Fi,"r",stdin);
    //freopen(Fo,"w",stdout);
    cin>>a>>b;
    n=a.size();
    m=b.size();
    for(int i=0; i<n; i++)
    {
        string tg;
        tg="";
        for(int j=0; j<=i; j++)
            tg=tg+a[j];
        A[++da]=tg;
    }
    for(int i=0; i<m; i++)
    {
        string tg;
        tg="";
        for(int j=0; j<=i; j++)
            tg=tg+b[j];
        B[++db]=tg;
    }
    vector<string>vt;
    for(int i=1; i<=da; i++)
    for(int k=1; k<=db; k++)
        vt.push_back(A[i]+B[k]);
    sort(vt.begin(),vt.end(),cmp);
    cout<<vt[0];

    return 0;
}
