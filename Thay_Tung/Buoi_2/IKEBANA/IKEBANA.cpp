#include <bits/stdc++.h>
using namespace std;
const int64_t p=1e9+7;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<int64_t> h(n),fl(n),fr(n+1);
    vector<int> a(n),ans;
    h[0]=1;
    for (int i=1; i<n; i++) h[i]=h[i-1]*p;

    for(int i=0; i<n; i++) cin>>a[i];
    fl[0]=a[0]; fr[n-1]=a[n-1]; fr[n]=0;

    for(int i=1; i<n; i++) fl[i]=fl[i-1]*p+a[i];
    for(int i=n-2; i>=0; i--) fr[i]=fr[i+1]*p+a[i];

    ans.push_back(n);

    for(int i=0; i<n/2; i++)
       if ((fr[i+1]-fr[2*i+2]*h[i+1])==fl[i]) ans.push_back(n-i-1);

    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';
    return 0;
}
