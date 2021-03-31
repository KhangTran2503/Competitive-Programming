#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
#define h 100003
using namespace std;
int64_t p[27],f[N];
string s;
int q,n;

void init()
{
    n=s.size();
    p[0]=1;
    for(int i=1; i<=26; i++) p[i]=p[i-1]*h;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    init();
    for(int i=1; i<=n; i++)
        f[i]=f[i-1]+p[s[i-1]-96];
    cin>>q;
    while (q--)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        if (f[y]-f[x-1]==f[v]-f[u-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
