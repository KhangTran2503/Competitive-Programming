#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int n,d,m;

bool check(int x,int y)
{
    if (x-y+d<0) return false;
    if (x-y-d>0) return false;
    if (x+y-d<0) return false;
    if (x+y+d-2*n>0) return false;
    return true;

}

int main()
{
      cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
      cin>>n>>d;
      cin>>m;
      while(m--)
      {
          int x,y;
          cin>>x>>y;
          if (check(x,y)) cout<<"YES"<<'\n';
          else cout<<"NO"<<'\n';
      }
      return 0;
}
