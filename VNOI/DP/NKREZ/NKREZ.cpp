#include <iostream>
#include <bits/stdc++.h>
#define N int(1e4)+5
using namespace std;
typedef pair<int,int> ii;
ii a[N];
int n,f[N],ST[4*N];

int Find(int x,int r)
{
    int l=1,pos=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if (a[mid].first<=x)
        {
            pos=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return pos;
}

void update(int id,int l,int r,int pos,int val)
{
    if (pos<l || pos>r || l>r) return;
    if (l==r)
    {
        ST[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    ST[id]=max(ST[2*id],ST[2*id+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return ST[id];
    int mid=(l+r)>>1;
    return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+1+n);

    int res=0;
    for(int i=1; i<=n; i++)
    {
        f[i]=a[i].first-a[i].second;
        int pos=Find(a[i].second,i-1);
        if (pos>0)
        {
            f[i]+=get(1,1,n,1,pos);
        }
        update(1,1,n,i,f[i]);
        res=max(res,f[i]);
    }
    cout<<res;
    return 0;
}
