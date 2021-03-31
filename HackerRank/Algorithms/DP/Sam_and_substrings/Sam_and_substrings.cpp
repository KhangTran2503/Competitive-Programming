/*
     Goi dp[i] la tong tao duoc khi den so thu i
     dp[i]=dp[i-1]+(10^i *a1+10^(i-1)*a2*2+....+i*ai)

     De xu li tong tren, tao mang Sum[i]:
     Sum[i]=(Sum[i-1]*10+i*ai)


*/
#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+7;
ll Pow[N],Sum[N],dp[N];
string n;
int len;


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    len=n.size();
    Sum[0]=0;
    for(int i=1; i<=len; i++)
       Sum[i]=(Sum[i-1]*10+(n[i-1]-'0')*i)%Mod;

    dp[0]=0;
    for(int i=1; i<=len; i++) dp[i]=(dp[i-1]+Sum[i])%Mod;
    cout<<dp[len];
    return 0;
}
