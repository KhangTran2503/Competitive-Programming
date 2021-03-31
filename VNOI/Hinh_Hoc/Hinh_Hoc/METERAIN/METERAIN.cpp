#include <bits/stdc++.h>
#define X first
#define Y second
#define N 5005
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ii a[N];
int n,m;

ii Vec(ii A, ii B) {return ii(B.X-A.X,B.Y-A.Y);}
bool CCW(ii O,ii A,ii B)
{
    ii OA=Vec(O,A);
    ii AB=Vec(A,B);
    return (ll)OA.X*(ll)AB.Y>(ll)OA.Y*(ll)AB.X;
}


bool check(ii p)
{
    int l=2,r=n;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (CCW(a[1],a[mid],p)) l=mid;
        else r=mid;
    }
    return (CCW(a[1],a[l],p) && CCW(a[l],a[r],p) && CCW(a[r],a[1],p));
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i].X>>a[i].Y;
    cin>>m;
    while (m--)
    {
       ii p;
       cin>>p.X>>p.Y;
       if (check(p)) cout<<"YES\n";
       else cout<<"NO\n";
    }
    return 0;
}
