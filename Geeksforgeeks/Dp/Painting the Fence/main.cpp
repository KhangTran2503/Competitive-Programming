///   f[i]=(k-1)*(f[i-1]+f[i-2])
///
#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+7;
int n,t,k;
ll dp[N];

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        dp[1]=k; dp[2]=(k*k)%Mod;
        for(int i=3; i<=n; i++)
            dp[i]=((k-1)*((dp[i-1]+dp[i-2])%Mod))%Mod;
        cout<<dp[n]<<'\n';


    }
    return 0;
}
