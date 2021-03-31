#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+7;
ll f[105];
int n,t,maxn;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    maxn=1;
    f[0]=f[1]=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if (n<=maxn) cout<<f[n]<<'\n';
        else {
            for(int i=maxn+1; i<=n; i++) f[i]=(f[i-1]+((i-1)*f[i-2])%Mod)%Mod;
            cout<<f[n]<<'\n';
        }
        maxn=max(maxn,n);
    }

    return 0;
}
