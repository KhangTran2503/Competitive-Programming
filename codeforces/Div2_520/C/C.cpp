#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
const ll Mod=(ll)(1e9)+7;
int s[N]={0};
ll Pow2[N];
int n,q;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>q;
    Pow2[0]=1;
    for(int i=1; i<=n; i++){
        char x;
        cin>>x;
        if (x=='1') s[i]=s[i-1]+1;
        else s[i]=s[i-1];
        Pow2[i]=(Pow2[i-1]*2)%Mod;
    }

    while(q--){
        int L,R;
        cin>>L>>R;
        int len=s[R]-s[L-1];
        ll res=((Pow2[len]-1+Mod)%Mod*Pow2[R-L+1-len])%Mod;
        cout<<res<<'\n';
    }
    return 0;
}
