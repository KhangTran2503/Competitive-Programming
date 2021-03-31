//giai thuat nay se tim ra cap x,y co |x|+|y| min
#include <bits/stdc++.h>

using namespace std;
int64_t a,b;

int64_t gcdExtended(int64_t a,int64_t b,int64_t &x,int64_t &y)
{
    if (a==0)
    {
        x=0;
        y=1;
        return b;
    }
    int64_t g,x1,y1;
    g=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    while(cin>>a>>b)
    {
        int64_t x,y,d;
        d=gcdExtended(a,b,x,y);
        if (a==b)
        {
            x=0; y=1;
        }
        cout<<x<<' '<<y<<' '<<d<<'\n';
    }
    return 0;
}
