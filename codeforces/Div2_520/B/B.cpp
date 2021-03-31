#include <iostream>
#include <bits/stdc++.h>
#define N int(1e6)+5
using namespace std;
typedef pair<int,int> ii;
int okprime[N]={0};
int n;

void Era(int n){
    int sqrt_n=int(sqrt(n));
    for(int i=2; i<=n; i++)
    if (!okprime[i]){
        okprime[i]=i;
        if (i<=sqrt_n)
        for (int j=i*i; j<=n; j+=i)
            if (okprime[j]==0) okprime[j]=i;
    }
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    if (n==1){
        cout<<1<<' '<<0;
        return 0;
    }
    Era(n);
    vector<ii> d;
    while (n>1)
    {
        if (d.empty()) d.push_back(ii(okprime[n],1));
        else {
            if (okprime[n]==d[d.size()-1].first) d[d.size()-1].second++;
            else d.push_back(ii(okprime[n],1));
        }
        n/=okprime[n];
    }

    //for(ii x: d) cout<<x.first<<' '<<x.second;

    int minp=100,maxp=0;
    for(ii x:d) {
        minp=min(x.second,minp);
        maxp=max(x.second,maxp);
    }

    int res1=0;
    for (int i=0; i<=20; i++)
       if (1<<i >= maxp){
        res1=i;
        break;
    }
    int res=1;
    for(ii x: d) res*=x.first;
    cout<<res<<' '<<res1+((maxp!=minp) ||(maxp&(maxp-1)));
    return 0;
}
