 #include <iostream>
#include <bits/stdc++.h>
using namespace std;
int X,n,dp[1005][105]={0};


int Pw(int x,int y){
    int res=1;
    while (y){
        if (y&1) res*=x;
        x=x*x;
        y>>=1;
    }
    return res;
}

int Calc(int u,int num){

    if (u==0 && num==0) return dp[0][0]=1;
    if (u<0 || num<0) return 0;
    if (dp[u][num]!=0) return dp[u][num];
    int res=0;
    int tmp=Pw(num,n);
    res+=Calc(u,num-1);
    if (tmp<=u) res+=Calc(u-tmp,num-1);
    return dp[u][num]=res;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>X>>n;
    //memset(dp,-1,sizeof(dp));
    int i=1;
    while (Pw(i,n)<=X) i++;
    cout<<Calc(X,i);
    return 0;
}
