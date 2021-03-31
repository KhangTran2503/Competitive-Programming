#include<bits/stdc++.h>
#define N 3*int(1e5)+5
#define oo int(1e9)
using namespace std;
typedef pair<int,int> ii;
int a[N],n,pos[N],pre[N],f[N],Tr[N];


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];

    int x_1=0,x_n=0;
    for(int i=1; i<=n; i++)
    {
        if (a[i]==a[1]) x_1++;
        if (a[i]==a[n]) x_n++;
    }
    if (x_1<=1 || x_n<=1)
    {
        cout<<0;
        return 0;
    }

    for (int i=n; i>=1; i--)
    {
        pre[i]=pos[a[i]];
        pos[a[i]]=i;
    }

    f[1]=1;
    for(int i=2; i<=n; i++) f[i]=oo;
    for(int i=2; i<=n; i++)
    {
        int Minx=oo,idmin;
        for (int j=i-1; j>=1; j--)
          if (pre[j]>=i && f[j]<Minx)
        {
            Minx=f[j];
            idmin=j;
        }
        if (Minx!=oo)
        {
            f[i]=Minx+1;
            Tr[i]=idmin;
        }
    }

    if (f[n]<oo)
    {
        cout<<f[n]-1<<'\n';
        int u=n;
        vector<int> ans;
        while (u!=1)
        {
            ans.push_back(Tr[u]);
            u=Tr[u];
        }
        for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';

    }
    else cout<<0;



}
