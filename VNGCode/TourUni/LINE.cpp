#include <bits/stdc++.h>
#define N int(1e5)+5
typedef long long ll;
const ll oo = (ll)(1e17);
using namespace std;
struct Node
{
    ll Max,Min;
    Node(){};
    Node(ll Ma,ll Mi)
    {
        Max=Ma;
        Min=Mi;
    }
} nodes[4*N];
ll rmin,rmax,a[N];
int n,q;
 
void update(int id,int l,int r)
{
    if (l==r) nodes[id]=Node(a[l],a[l]);
    else
    {
        int mid=(l+r)>>1;
        update(2*id,l,mid);
        update(2*id+1,mid+1,r);
        nodes[id].Min=min(nodes[2*id].Min,nodes[2*id+1].Min);
        nodes[id].Max=max(nodes[2*id].Max,nodes[2*id+1].Max);
    }
}


void get(int id,int l,int r ,int u,int v)
{
    if (r<u || l>v) return;
    if (u<=l && r<=v)
    {
        rmax=max(rmax,nodes[id].Max);
        rmin=min(rmin,nodes[id].Min);
        return;
    }
    int mid=(l+r)>>1;
    get(2*id,l,mid,u,v);
    get(2*id+1,mid+1,r,u,v);
 
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>a[i];
    update(1,1,n);
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        rmax=0, rmin=oo;
        get(1,1,n,u,v);
        cout<<rmax-rmin<<'\n';
    }
    return 0;
}