#include <iostream>
#include <bits/stdc++.h>
#define N 5*int(1e5)+5
using namespace std;
int nodes[4*N],a[N],n,q;
int high=1;

void build(int id,int l,int r)
{
    if(l==r)
    {
        nodes[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    nodes[id]=__gcd(nodes[2*id],nodes[2*id+1]);
}
//================================
void update(int id,int l,int r,int pos,int val)
{
    if (pos<l || pos>r || r<l) return;
    if(l==r)
    {
        nodes[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    nodes[id]=__gcd(nodes[2*id],nodes[2*id+1]);
}
//==================================
void get(int id,int l,int r,int u,int v,int& ans,int x)
{
    if (r<u || l>v) return;
    if (u<=l && r<=v)
    {
        if (nodes[id]%x==0) return;
        int pos=id;
        while (pos<high)
        {
            if (nodes[2*pos]%x)
            {
                if (nodes[2*pos+1]%x)
                {
                    ans+=2; return;
                }
                pos*=2;
            }
            else pos=pos*2+1;
            ans++;
            return;
        }
    }
    int mid=(l+r)>>1;
    get(2*id,l,mid,u,v,ans,x);
    if (ans>=2) return;
    get(2*id+1,mid+1,r,u,v,ans,x);

}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    //scanf("%d",&n);
    for(int i=1; i<=n; i++) cin>>a[i];
         //scanf("%d",&a[i]);
    build(1,1,n);
    for(; high<n; high*=2);
    cin>>q;
    //scanf("%d",&q);
    while (q--)
    {
        int c;
        cin>>c;
        //scanf("%d",&c);
        if (c==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            int t=0;
            get(1,1,n,l,r,t,x);
            if (t<=1) cout<<"YES\n";
            else cout<<"NO\n";

        }
        else
        {
            int pos,y;
            cin>>pos>>y;
            update(1,1,n,pos,y);
        }
    }
    return 0;
}
