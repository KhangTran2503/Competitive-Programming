#include <iostream>
#include <bits/stdc++.h>
#define Name "B"
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
int dx[]={0,0,1,-1},
    dy[]={1,-1,0,0};
ii s, t;
int n,m,res=0;
char c;
string h;
int d[6],x[6],a[55][55];

bool inside(int u,int v)
{
    if (u<1 || v<1 || u>n || v>m) return false;
    return true;
}
//======================
bool check()
{
    int u=s.x, v=s.y;
    for (int i=0; i<h.size(); i++)
    {
        int hh=h[i]-'0';
        u+=dx[x[hh]];
        v+=dy[x[hh]];
        if (!inside(u,v) || a[u][v]) return false;
        if (t==ii(u,v)) return true;
    }
    return false;
}
//=======================
void Try(int i)
{
    for(int j=0; j<4; j++)
      if (!d[j])
    {
        d[j]=1;
        x[i]=j;
        if (i==3)
        {
            if (check()) res++;
        }
        else Try(i+1);
        d[j]=0;
    }
}
//===========================
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
         cin>>c;
         a[i][j]=0;
         if (c=='#') a[i][j]=1;
         if (c=='S') s=ii(i,j);
         if (c=='E') t=ii(i,j);

    }
    cin>>h;
    memset(d,0,sizeof(d));
    Try(0);
    cout<<res;
    return 0;
}
