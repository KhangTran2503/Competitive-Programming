#include <iostream>
#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> g[N];
int n;
bool ok=true;

void check(int u)
{
    int tg=0;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if (g[v].empty()) tg++;
        else check(v);
        if (!ok) return;
    }
    if (tg<3)
    {
        ok=false;
        return;
    }
}
//=====================
int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d",&n);
    for (int i=2; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    check(1);
    if (ok) printf("%s","YES");
    else printf("%s","NO");
    return 0;
}
