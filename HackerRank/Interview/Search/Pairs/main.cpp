#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
ll k,arr[N];
int n;
map<ll,ll> d;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        d[arr[i]]++;
    }
    ll res=0;
    for(int i=1; i<=n; i++)
    {
        res+=ll(d[arr[i]])*ll(d[arr[i]+k]);
    }
    cout<<res;
    return 0;
}
