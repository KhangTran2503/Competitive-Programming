///goi dp[i][0] la tong lon nhat khi chon so thu i la 1
///goi dp[i][1] la tong lon nhat khi chon so thu i la b[i]

/// dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(1-b[i-1]))
/// dp[i][1]=max(dp[i-1][1]+abs(b[i]-b[i-1),dp[i-1][0]+abs(b[i]-1))

#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int dp[N][2],b[N],n,t;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++) cin>>b[i];
        dp[1][0]=dp[1][1]=0;

        for(int i=2; i<=n; i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(1-b[i-1]));
            dp[i][1]=max(dp[i-1][1]+abs(b[i]-b[i-1]),dp[i-1][0]+abs(b[i]-1));
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}
