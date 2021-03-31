//dung multiset
#include <bits/stdc++.h>
#define N 132676
#define x first
#define y second
#define oo int(1e9)
using namespace std;
multiset<int> check[4];
int a[4][N];
int n;

//============================================
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int u,v,uu,vv;
        cin>>u>>v>>uu>>vv;
        a[0][i]=u;
        a[1][i]=v;
        a[2][i]=uu;
        a[3][i]=vv;
        for(int j=0; j<4; j++)
            check[j].insert(a[j][i]);
    }

    for(int i=1; i<=n; i++)
    {
        for (int j=0; j<4; j++) check[j].erase(check[j].find(a[j][i]));//thu bo 1 hinh vuong va kiem tra
        int MaxX=*check[0].rbegin();
        int MinX=*check[2].begin();
        int MaxY=*check[1].rbegin();
        int MinY=*check[3].begin();

        if (MaxX<=MinX && MaxY<=MinY)
        {
            cout<<MaxX<<' '<<MaxY;
            break;
        }

        for(int j=0; j<4; j++) check[j].insert(a[j][i]);
    }

    return 0;
}
