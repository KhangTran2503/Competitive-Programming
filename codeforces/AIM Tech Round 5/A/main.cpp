#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int minX,maxX,minY,maxY;
int n,m;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;

    minX=minY=oo;
    maxX=maxY=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
          char x;
          cin>>x;
          if (x=='B')
          {
              minX=min(minX,i);
              maxX=max(maxX,i);
              minY=min(minY,j);
              maxY=max(maxY,j);
          }

    }
    cout<<(minX+maxX)/2<<' '<<(minY+maxY)/2;
}
