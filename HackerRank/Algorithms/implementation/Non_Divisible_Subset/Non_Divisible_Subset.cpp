#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,k,d[105];


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        d[x%k]++;
    }
    vector<ii> Mod(k);
    for(int i=0; i<k; i++) Mod[i]=ii(d[i],i);
    sort(Mod.rbegin(),Mod.rend());/// chon giam dan
    int res=0;
    for (auto x:Mod){
        if (d[x.second]>0)
        {
            if (x.second==0 || x.second*2==k) res++;///TH chi lay duoc 1 phan tu
            else
            {
               res+=d[x.second];
               d[k-x.second]=0;
            }
        }
    }
    cout<<res;
    return 0;
}
