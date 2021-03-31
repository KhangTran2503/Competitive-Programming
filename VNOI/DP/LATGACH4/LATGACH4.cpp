#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>
#define vi vector<ll>
using namespace std;
const ll Mod=111539786;
int t,n;


matrix cs(2,vi(2,0));
matrix ans(2,vi(2,0));
matrix I(2,vi(2,0));

void init()
{
    I[0][0]=I[1][1]=1;
    cs[0][1]=cs[0][0]=cs[1][0]=1;
    ans[0][0]=ans[1][0]=1;
}

matrix operator* (matrix a,matrix b)
{
    matrix c(2,vi(2,0));
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
           for(int k=0; k<2; k++)
              c[i][j]=(1LL*(a[i][k]*b[k][j])%Mod + c[i][j])%Mod;
     return c;
}

matrix Pow_m(int y)
{
    matrix tmp(I);
    matrix u(cs);
    while(y)
    {
        if (y&1) tmp=u*tmp;
        u=u*u;
        y>>=1;

    }
    return tmp;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    init();
    while(t--)
    {
        cin>>n;
        init();
        matrix res=Pow_m(n-1)*ans;
        cout<<res[0][0]<<'\n';

    }

    return 0;
}
