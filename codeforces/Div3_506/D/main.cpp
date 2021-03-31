#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int a[N][11];
int cs[N];
map<int,int> f[11];
int n;
int k;

int call_digit(int x)
{
    int res=0;
    while (x>0)
    {
        res++;
        x/=10;
    }
    return res;
}
//==========================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i][0];
        cs[i]=call_digit(a[i][0]);
        a[i][0]%=k;
        f[cs[i]][a[i][0]]++;
    }

     ll res=0LL;
    for(int i=1; i<=n; i++)
      for(int j=1; j<=10; j++)
         {
             if (a[i][j-1]==0) a[i][j]=0;
             else a[i][j]=(ll)(a[i][j-1]*10LL)%k;
             res+=(ll)f[j][(k-a[i][j])%k];
             if (j==cs[i] && (ll)(a[i][0]+a[i][j])%k==0) res--;
         }
   cout<<res<<'\n';


 /*   for(int i=1; i<=n; i++) cout<<cs[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; i++)
   {
       for(int j=0; j<=9; j++) cout<<a[i][j]<<' ';
       cout<<'\n';
   }



    for(__typeof(f.begin()) it=f.begin(); it!=f.end(); it++)
        cout<<(it->first).first<<' '<<(it->first).second<<' '<<it->second<<'\n'; */
    return 0;
}
