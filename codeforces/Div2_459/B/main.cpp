#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<string,int> dd;
int n,m;
string s[1005];

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    //freopen("Test.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        string x;
        cin>>s[i]>>x;
        dd[x]=i;
    }
    for(int i=1; i<=m; i++)
    {
        string S,ip;
        cin>>S>>ip;
        ip.erase(ip.size()-1,1);
        int t=dd[ip];
        if (t)
        {
            cout<<S<<' '<<ip<<"; "<<'#'<<s[t]<<'\n';
        }
    }
    return 0;
}
