#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x); i<=(y); i++)
#define f first
#define s second
#define N 105
#define Name "A"
using namespace std;
typedef pair<int,int> ii;
ii a[N];
int n,m;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n>>m;
    fto(i,1,n) cin>>a[i].f>>a[i].s;
    sort(a+1,a+1+n);
    int last=0;
    fto(i,1,n)
      if (a[i].f<=last) last=max(last,a[i].s);
      else break;
    if (last>=m) cout<<"YES";
    else cout<<"NO";
    return 0;
}
