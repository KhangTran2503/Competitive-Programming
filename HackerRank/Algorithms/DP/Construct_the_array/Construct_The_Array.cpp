///goi dp[i][0] la so luong mang  ket thuc tai vtri i ma a[i]!=x
///goi dp[i][1] la so luong mang  ket thuc tai vtri i ma a[i]=x
/// dp[i][1]=dp[i-1][1]
/// dp[i][0]=(k-1)*dp[i-1][1]+(k-2)*dp[i-1][0]

/// dp[1][0]= x==1 ? 0 : 1
/// dp[1][1]= x==1 ? 1 : 0
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
const ll MOD=ll(1e9)+7;
ll dp[N][2];
int n,k,x;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k>>x;
    dp[1][1]=(x==1 ? 1 : 0);
    dp[1][0]=(x==1 ? 0 : 1);
    for(int i=2; i<=n; i++)
    {
       dp[i][1]=dp[i-1][0]%MOD;
       dp[i][0]=((ll(k-1)*dp[i-1][1])%MOD + (ll(k-2)*dp[i-1][0])%MOD)%MOD;

    }
    cout<<dp[n][1];
    return 0;
}
