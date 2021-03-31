#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1005];
int n,m;


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=min(n,m); i++){
        int id=(i%m)*(i%m)%m;
        int Begin=i;
        int End=i;
        for(int j=n; j>=1; j--)
            if (j%m==i%m){
               End=j;
               break;
            }
        int cnt=(End-Begin)/m +1;
        f[id]+=(ll)cnt;

    }
    ll ans=0;
    for(int i=0; i<m; i++)
        ans+=f[i]*f[(m-i)%m];
    cout<<ans;
    return 0;
}
