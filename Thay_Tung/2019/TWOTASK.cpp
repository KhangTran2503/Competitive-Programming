#include <iostream>
#include <algorithm>
using namespace std;

double r1,r2,r3,r4,a,b,c,v0,v1,v2;
int main()
{
    cin >>a >> b>> c>> v0 >> v1 >> v2;
    a=min(a,b+c);
    b=min(b,a+c);
    c=min(c,a+b);
    r1=a/v0+c/v1+b/v2;
    r2=a/v0+a/v1+b/v0+b/v1;
    r3=b/v0+c/v1+a/v2;
    cout.precision(20);
    cout << min(r1,min(r2,r3));
}
