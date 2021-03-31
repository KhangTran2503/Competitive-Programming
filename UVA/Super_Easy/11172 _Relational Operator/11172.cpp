#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
ll a,b;

int main()
{
   // cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        if (a>b) cout<<'>'<<'\n';
        if (a<b) cout<<'<'<<'\n';
        if (a==b) cout<<'='<<'\n';
    }
    return 0;
}
