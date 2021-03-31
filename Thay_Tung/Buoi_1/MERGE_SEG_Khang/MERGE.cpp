///   dung hai bien L,R de cap nhat vi tri trai nhat va phai nhat
///
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;
int64_t ans;

int main()
{
    //cout << "Hello world!" << endl;
    //freopen("Test.INP","r",stdin);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<ii> a(n);
    for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;

    sort(a.begin(),a.end());
    int L=a[0].first,R=a[0].second;
    ans=0;
    for(int i=1; i<n; i++)
    {
        if (a[i].first>R)
        {
            ans+=(R-L);
            L=a[i].first; R=a[i].second;
        }
        else R=max(R,a[i].second);
    }
    ans+=(R-L);
    cout<<ans;
    return 0;
}
