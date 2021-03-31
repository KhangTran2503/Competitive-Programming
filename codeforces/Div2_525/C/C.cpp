#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<n+1<<'\n';
    cout<<1<<' '<<n<<' '<<500000<<'\n';
    for(int i=0; i<n; i++)
        cout<<2<<' '<<i+1<<' '<<a[i]+500000-i<<'\n';

    return 0;
}
