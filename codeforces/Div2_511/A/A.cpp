#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    if (n%3==2) cout<<1<<' '<<2<<' '<<n-3;
    else cout<<1<<' '<<1<<' '<<n-2;
    return 0;
}
