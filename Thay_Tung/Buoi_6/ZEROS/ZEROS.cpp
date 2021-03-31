#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> prime;
vector<ii> d;
int n,b,fre[1005];

void Era(int n)
{
    int sqrt_n=int(sqrt(n));
    memset(fre,0,sizeof(fre));
    for (int i=2; i<=sqrt_n; i++)
    {
        if (!fre[i])
        {
            prime.push_back(i);
            int j=i*i;
            while (j<=n)
            {
                fre[j]=1;
                j+=i;
            }
        }
    }

}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>b;
    Era(b);
    for (int x:prime)
      {
          if (b%x==0)
          {
              d.push_back(ii(x,0));
              while (b%x==0)
              {
                  d[d.size()-1].second++;
                  b/=x;
              }
          }
      }
    if (b!=1) d.push_back(ii(b,1));

    int ans=int(1e9);
    for(auto x:d)
    {
        int cnt=0;
        int u=n;
        while (u>0)
        {
           cnt+=(u/x.first);
           u/=x.first;
        }
        ans=min(ans,cnt/x.second);

    }
    cout<<ans;
    return 0;
}
