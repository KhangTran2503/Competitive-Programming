#include <bits/stdc++.h>
#define db double
#define sqr(x) (db)(x)*(db)(x)
#define Name "C"
#define N 1005
using namespace std;
int x[N];
int n,r;
db h[N]={0};

bool check(int i,int j)
{
    if (abs(x[i]-x[j])<=2*r) return true;
    return false;
}
//==================
db dis(db a, db b)
{
    return sqrt(sqr(a)-sqr(b));
}
//===================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n>>r;
    for (int i=1; i<=n; i++) cin>>x[i];
    h[1]=(db)r;
    for (int i=2; i<=n; i++)
    {
        bool ok=true;
        for (int j=i-1; j>=1; j--)
            if (check(i,j))
        {
             h[i]=max(h[i],h[j]+dis((db)(2*r),(db)abs(x[i]-x[j])));
             ok=false;
        }
       if (ok) h[i]=(db)r;
    }
    for (int i=1; i<=n; i++)
     cout<<fixed<<setprecision(12)<<h[i]<<' ';
    return 0;
}
