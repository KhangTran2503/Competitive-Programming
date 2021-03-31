#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
vector<int> g[N];
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0);  cout.tie(0);
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        int x;
        cin>>x;
        g[i].push_back(x);
    }
    g[1].push_back(0);
    vector<int> ans;
    int u=n;
    do
    {
        ans.push_back(u);
        u=g[u][0];
    }
    while (u!=0);
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';
    return 0;
}
