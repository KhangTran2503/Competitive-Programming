#include<bits/stdc++.h>
#define N 5005
using namespace std;
int n,a[N];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        int u=a[i],v=a[u];
        if (a[v]==i)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
