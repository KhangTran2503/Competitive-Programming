#include <bits/stdc++.h>
using namespace std;
int n,m;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cout<<'1';
    cout<<'\n';
    for(int i=1; i<=n-1; i++) cout<<'8';
    cout<<'9';
    return 0;
}
