#include <iostream>
#include <bits/stdc++.h>
#define N 2005
using namespace std;
char c[N][N];
int n,m,k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>c[i][j];

    int res=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=m;)
        if (c[i][j]=='.')
        {
            int h=j;
            while (h<=m && c[i][h]=='.') h++;
            res+=max(h-j-k+1,0);
            j=h;
        }
        else j++;
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n;)
        if (c[i][j]=='.')
        {
            int h=i;
            while (h<=n && c[h][j]=='.') h++;
            res+=max(h-i-k+1,0);
            i=h;
        }
        else i++;
    }
    if (k==1) cout<<res/2;
    else cout<<res;

    return 0;
}
