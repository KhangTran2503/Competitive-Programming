#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int a[N],b[N],c[N],lena,lenb,lenc;


void process()
{
     sort(a+1,a+1+lena);
     sort(b+1,b+1+lenb);
     sort(c+1,c+1+lenc);
     lena=unique(a+1,a+1+lena)-(a+1);
     lenb=unique(b+1,b+1+lenb)-(b+1);
     lenc=unique(c+1,c+1+lenc)-(c+1);
     ll res=0;
     int k1=1,k2=1;
     for(int i=1; i<=lenb; i++)
     {

         while (k1<=lena && a[k1]<=b[i]) k1++;
         while (k2<=lenc && c[k2]<=b[i]) k2++;
         res+=ll(ll(k1-1)*ll(k2-1));
     }
     cout<<res;

}
//===============================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    freopen("Test.INP","r",stdin);
    cin>>lena>>lenb>>lenc;
    for(int i=1; i<=lena; i++) cin>>a[i];
    for(int i=1; i<=lenb; i++) cin>>b[i];
    for(int i=1; i<=lenc; i++) cin>>c[i];

    process();
    return 0;
}
