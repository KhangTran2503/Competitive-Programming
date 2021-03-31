#include<bits/stdc++.h>
using namespace std;
int a[105],dp[105],t;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    for(int i=1; i<=t; i++) cin>>a[i];
    for(int i=1; i<=100; i++)
      for (int j=2; j<=7; j++)
            if (i>=j) dp[i]=dp[i-j]+1;
    for(int i=1; i<=t; i++) cout<<dp[a[i]]<<'\n';
    return 0;
}
