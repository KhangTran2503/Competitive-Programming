#include <bits/stdc++.h>
#define N 1005
using namespace std;
int f[N][N];
int kt[N][N];
int n,m;
int check1(int a,int b)
{
    for(int i=a; i<=a+2; i++)
    for(int j=b; j<=b+2; j++)
    if(i!=a+1 || j!=b+1)
        if(!f[i][j]) return 0;
    return 1;
}
void update1(int a,int b)
{
    for(int i=a; i<=a+2; i++)
    for(int j=b; j<=b+2; j++)
    if(i!=a+1 || j!=b+1)
        kt[i][j]=1;

}
int main()
{
    //freopen(Fi,"r",stdin);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if(c=='#')f[i][j]=1;
        else f[i][j]=0;
        kt[i][j]=0;
    }
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    if(f[i][j] && check1(i,j))
        update1(i,j);

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    if(f[i][j] && !kt[i][j])
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}
