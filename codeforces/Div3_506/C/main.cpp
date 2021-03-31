#include <bits/stdc++.h>
#define l first
#define r second
#define oo int(1e9)
#define N 3*int(1e5)+5
using namespace std;
typedef pair<int,int> ii;
ii a[N];
int n;
int minr=oo,r1,r2;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        {
            int x,y;
            cin>>x>>y;
            a[i]=ii(x,y);
        }
    sort(a+1,a+1+n);

    for(int i=1; i<=n; i++)
     if (minr>=a[i].r)
     {
         minr=a[i].r;
         r1=i;
     }

    minr=oo;
    for(int i=1; i<=n; i++)
       if(minr>=a[i].r && i!=r1)
    {
        minr=a[i].r;
        r2=i;
    }


    if (r1==n) cout<<max(a[r2].r-a[n-1].l,0);
    else cout<<max(0,max(a[r1].r-a[n-1].l,a[r2].r-a[n].l));
    return 0;
}
