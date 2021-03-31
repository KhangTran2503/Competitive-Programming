/// goi dp[i][j] la so luong day co chieu dai j , 1->i
///   dp[i][j]=dp[i-1][j-1]+dp[i-1][j] . Neu a[i]%j
///            dp[i-1][j]

///    chi de y toi nhung j la uoc cua a[i]
///    va rut gon 1 chieu
#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+7;
int a[N],n;
vector<int> divi[N];
ll dp[N],res;

void init(){
    for (int i=1; i<=n; i++){
        for(int j=1; j*j<=a[i]; j++)
            if (a[i]%j==0){
                if (j<=n) divi[i].push_back(j);
                if (j!=a[i]/j && a[i]/j<=n) divi[i].push_back(a[i]/j);
            }
        sort(divi[i].rbegin(),divi[i].rend());
    }
    dp[0]=1;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init();

    for (int i=1; i<=n; i++){
        for (auto &x: divi[i]){
            //if (x>i) break;
            dp[x]=(dp[x]+dp[x-1])%Mod;
        }
    }
    res=0;
    for(int i=1; i<=n; i++)
        res=(res+dp[i])%Mod;


    /*for(int i=1; i<=n; i++){
        for(auto x: divi[i]) cout<<x<<' ';
        cout<<'\n';
    }*/
    cout<<res;
    return 0;
}
