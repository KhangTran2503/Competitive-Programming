#include <bits/stdc++.h>
using namespace std;
int64_t a,b,x,y;

int64_t gcdExtended(int64_t a,int64_t b,int64_t &x,int64_t &y)
{
    if (a==0)
    {
        x=0;
        y=1;
        return b;
    }
    int64_t x1,y1,d;
    d=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;

}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>a>>b;
    int64_t g=gcdExtended(a,b,x,y);
    cout<<x<<' '<<y<<' '<<g;
    return 0;
}
