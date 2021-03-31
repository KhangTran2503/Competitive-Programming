#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long double ld;
typedef pair<ld,ld> ii;
ld ans;
vector<ii> point;

ld dis(ii u,ii v){
    return sqrt((ld)(u.X-v.X)*(u.X-v.X)+(ld)(u.Y-v.Y)*(u.Y-v.Y));
}
ld a,b,c,x1,x2,y1,y2;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;
    ans=abs(x1-x2)+abs(y1-y2);
    if (a==0 || b==0){
        cout<<fixed<<setprecision(8)<<ans;
        return 0;
    }

    ii pointA=ii((ld)x1,(ld)y1);
    ii pointB=ii((ld)x2,(ld)y2);
    point.push_back(ii(x1,(-c-a*x1)/(ld)b));
    point.push_back(ii((-c-b*y1)/(ld)a,y1));
    point.push_back(ii(x2,(-c-a*x2)/(ld)b));
    point.push_back(ii((-c-b*y2)/(ld)a,y2));
    for(int i=0; i<2; i++)
        for(int j=2; j<4; j++)
            ans=min(ans,dis(pointA,point[i])+dis(point[i],point[j])+dis(point[j],pointB));
    cout<<fixed<<setprecision(8)<<ans;

    return 0;
}
