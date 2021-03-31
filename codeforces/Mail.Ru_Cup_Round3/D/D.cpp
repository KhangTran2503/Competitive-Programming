#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int n,f[N];
vector<int> g[N];

int dfs(int u){
    if (g[u].empty()){
        f[1]++;
        return 1;
    }
    int tmp=0;
    for(int v:g[u])
       tmp+=dfs(v);
    f[tmp]++;
    return tmp;
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }

    dfs(1);
    for(int i=1; i<=n; i++)
      if (f[i]!=0)
         for(int j=1; j<=f[i]; j++) cout<<i<<' ';

    return 0;
}
