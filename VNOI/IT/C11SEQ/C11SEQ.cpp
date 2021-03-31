#include <bits/stdc++.h>
#define N 3*int(1e5)+5
using namespace std;
typedef long long ll;
ll a[N]={0},L,R;
int n;
int IT[4*N]={0};





void discretized(vector<ll> change)
{
    sort(change.begin(),change.end());
    change.erase(unique(change.begin(),change.end()),change.end());
    for(int i=0; i<=3*n; i++)
        a[i]=lower_bound(change.begin(),change.end(),a[i])-change.begin();

}

void update(int id,int l,int r,int pos)
{
    if (pos<l || pos>r || l>r) return;
    if (l==r)
    {
        IT[id]++;
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,pos);
    update(2*id+1,mid+1,r,pos);
    IT[id]=IT[2*id]+IT[2*id+1];
}

int Get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return IT[id];
    int mid=(l+r)>>1;
    return Get(2*id,l,mid,u,v)+Get(2*id+1,mid+1,r,u,v);
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>L>>R;
    vector<ll> change(3*n+3);
    change.push_back(a[0]);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        change.push_back(a[i]);
        a[i+n]=a[i]-R;
        change.push_back(a[i+n]);
        a[2*n+i]=a[i]-L;
        change.push_back(a[2*n+i]);
    }

    discretized(change);
    update(1,0,3*n+1,a[0]);

    ll res=0;
    for(int i=1; i<=n; i++)
    {
        res+=Get(1,0,3*n+1,a[i+n],a[2*n+i]);
        update(1,0,3*n+1,a[i]);
    }
    cout<<res;


    return 0;
}
