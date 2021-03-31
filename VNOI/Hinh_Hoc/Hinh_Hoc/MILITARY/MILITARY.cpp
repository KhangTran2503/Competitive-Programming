#include <bits/stdc++.h>
#define x first
#define y second
#define N 4005
using namespace std;
typedef pair<int,int> ii;
ii a[N];
int H[N],check[N];
int n,res;

ii vec(ii A,ii B) {return ii(B.x-A.x,B.y-A.y);}
bool ccw(ii A,ii B,ii C)
{
    ii AB=vec(A,B);
    ii BC=vec(B,C);
    return AB.x*BC.y>AB.y*BC.x;
}


void Hull()
{
    int k=0;
    for(int i=1; i<=n; i++)
    {
        while (k>=2 && ccw(a[H[k-1]],a[H[k]],a[i])) k--;
        H[++k]=i;
    }
    int t=k;
    for(int i=n-1; i>=1; i--)
    {
       while (k>=t && ccw(a[H[k-1]],a[H[k]],a[i])) k--;
        H[++k]=i;
    }

    memset(check,0,sizeof(check));
    for(int i=1; i<k; i++) check[H[i]]=1;
    int m=0;
    for(int i=1; i<=n; i++)
      if (!check[i]) a[++m]=a[i];
    n=m;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n);

    res=0;
    while(n>2)
    {
       res++;
       Hull();
    }
    cout<<res;
    return 0;
}
