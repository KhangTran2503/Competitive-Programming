#include <bits/stdc++.h>
#define N 105
using namespace std;
int f[N][N];
int n;
int res=0;
void dequi(int u)
{

    for(int i=u; i>=1; i--)
    for(int j=0; j<i; j++)
    if(f[i][j])
    {
        f[i][j]=f[j][i]=0;
        dequi(j);
        return;
    }
    res++;
}
int main()
{
    cin>>n;
    memset(f,-1,sizeof(f));
    for(int i=n; i>=1; i--)
    for(int j=0; j<i; j++)
    if(f[i][j])
    {
        f[i][j]=f[j][i]=0;
        dequi(j);
    }
    cout<<res;
    return 0;
}
