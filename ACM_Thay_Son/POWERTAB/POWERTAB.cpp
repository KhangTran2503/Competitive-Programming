#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vi;
ll n,m,x,X1,X2,Y1,Y2,Mod;
int q;

matrix I(2,vi(2,0));

void init()
{
    I[0][0]=I[1][1]=1;
}

matrix operator* (matrix a,matrix b)
{
    matrix c(2,vi(2,0));
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
          for(int k=0; k<2; k++)
            c[i][j]=((a[i][k]*b[k][j])%Mod+c[i][j])%Mod;
    return c;
}

ll fastpow(ll X,ll Y)
{
    ll tmp=1;
    while (Y)
    {
        if (Y&1) tmp=(tmp*X)%Mod;
        X=(X*X)%Mod;
        Y>>=1;
    }
    return tmp;
}

matrix fastpow(matrix a,ll Y)
{
    matrix tmp(I);
    matrix u(a);
    while (Y)
    {
        if (Y&1) tmp=tmp*u;
        u=u*u;
        Y>>=1;
    }
    return tmp;

}

ll get(ll l,ll r,ll p)
{
    if (l==r) return fastpow(p,l);
    matrix base(2,vi(2,0));
    base[0][0]=base[1][0]=p; base[1][1]=1;
    p=fastpow(p,l);
    base=fastpow(base,r-l);
    return (p*(base[1][0]+1))%Mod;


}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m>>x;
    cin>>q;
    init();
    while (q--)
    {
        cin>>X1>>X2>>Y1>>Y2>>Mod;
        ll tmp1=get(Y1,Y2,x);
        ll P=fastpow(x,m);
        ll tmp2=get(X1-1,X2-1,P);
        cout<<(tmp1*tmp2)%Mod<<'\n';

    }
    return 0;
}
