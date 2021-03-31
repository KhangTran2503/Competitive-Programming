
#include <bits/stdc++.h>
#define db double
using namespace std;
db d,a1,a2,v,t;

int main()
{
    cin>>d>>a1>>a2>>v>>t;
    db t1 = v/a1;
    db s1 = ((db)1/2.)*a1*t1*t1;

    db t2 = v/a2;
    db s2 = ((db)1/2.)*a2*t2*t2;

    db s3 = v*t;
    if(s1+s2+s3<=d)
    {
        db res=t1 + t2+ (d-s1-s2-s3)/v;
        cout<<fixed<<setprecision(12)<<res;
    }else
    {
        db b=(db)2.*t;
        db c=(db)-2.*d;
        db a= (db)1./(a1) + (db)1./(a2);
        db delta= (db)b*b - (db)4.*c*a;

        db res=((db)-b + sqrt(delta))/((db)2.*a);  ///tinh v'<v
        cout<<fixed<<setprecision(12)<<res/a1+res/a2+t;
    }
    return 0;
}
