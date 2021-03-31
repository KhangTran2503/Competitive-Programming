#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    n=unique(a.begin(),a.end())-a.begin();
    a.erase(unique(a.begin(),a.end()),a.end());
    //ll t=0;
    cout<<a[0]<<'\n';
    for(int i=1; i<min(n,k); i++){
        if (a[i]-a[i-1]>0) cout<<a[i]-a[i-1]<<'\n';
        else cout<<0<<'\n';
    }
    for(int i=min(n,k); i<k; i++) cout<<0<<'\n';
    return 0;
}
