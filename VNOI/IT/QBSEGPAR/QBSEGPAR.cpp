/// chat np + DP + roi rac
/// goi fmix[i] la so doan con it nhat chia thoa dk
///     fmax[i] la so doan con nhieu nhat thoa dk
///     Chat np theo M
///     fmin[i]=Min(fmin[j)+1 (s[i]-s[j]<=M) , roi rac hoa
#include <bits/stdc++.h>
#define N 15005
#define oo int(1e9)
using namespace std;
int a[N]={0},Fmax[N],Fmin[N];
int n,k;
struct Nodes
{
    int Max,Min;
    Nodes(){}
    Nodes(int Ma,int Mi):Max(Ma),Min(Mi){};

};
Nodes ST[4*N];


Nodes Combine(Nodes L,Nodes R)
{
    Nodes res;
    res.Max=max(L.Max,R.Max);
    res.Min=min(L.Min,R.Min);
    return res;
}

void update(int id,int l,int r,int pos,Nodes val)
{
    if (pos<l || pos>r) return;
    if (l==r)
    {

        ST[id].Max=max(ST[id].Max,val.Max);;
        ST[id].Min=min(ST[id].Min,val.Min);
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    ST[id]=Combine(ST[2*id],ST[2*id+1]);
}

Nodes Get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return Nodes(-oo,oo);
    if (u<=l && r<=v) return ST[id];
    int mid=(l+r)>>1;
    return Combine(Get(2*id,l,mid,u,v),Get(2*id+1,mid+1,r,u,v));
}


bool check(int M)
{
    vector<int> tmp(n+1);
    for(int i=0; i<=n; i++)
    {
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

    for(int i=1; i<=4*(n+1); i++)
    {
        ST[i].Max=-oo;
        ST[i].Min=oo;
    }

    Fmin[0]=Fmax[0]=0;
    int pos0=lower_bound(tmp.begin(),tmp.end(),a[0])-tmp.begin();
    update(1,0,n,pos0,Nodes(0,0));
    for(int i=1; i<=n; i++)
    {
        int pos1=lower_bound(tmp.begin(),tmp.end(),a[i]-M)-tmp.begin();
        Nodes fx=Get(1,0,n,pos1,n+1);
        Fmin[i]=fx.Min+1;
        Fmax[i]=fx.Max+1;
        int pos2=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
        update(1,0,n,pos2,Nodes(Fmax[i],Fmin[i]));

    }
    return (k>= Fmin[n] && k<=Fmax[n]);

}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int l=-oo,r=oo,res=0;
      while (l<=r)
      {
        int mid=(l+r)>>1;
        //int mid=1;
        if (check(mid))
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
     }
    cout<<res;
    return 0;
}
