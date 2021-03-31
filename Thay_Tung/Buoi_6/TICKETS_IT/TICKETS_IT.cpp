#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
struct Node
{
    int val;
    int lazy;
    Node(){}
    Node(int vl,int lz):val(vl),lazy(lz){}
};
Node ST[4*N];
int n,s,q;

void down(int id,int l,int r)
{
    if (ST[id].lazy!=0)
    {
        ST[id].val+=ST[id].lazy;
        if (l!=r)
        {
            ST[2*id].lazy=ST[id].lazy;
            ST[2*id+1].lazy=ST[id].lazy;
        }
        ST[id].lazy=0;
    }
}

void update(int id ,int l,int r ,int u,int v,int value)
{
      down(id,l,r);
      if (r<l || r<u || l>v) return;
      if (u<=l && r<=v)
      {
          ST[id].val+=value;
          if (l!=r)
          {
              ST[2*id].lazy+=value;
              ST[2*id+1].lazy+=value;
          }
          ST[id].lazy=0;
          return;

      }
      int mid=(l+r)>>1;
      update(2*id,l,mid,u,v,value);
      update(2*id+1,mid+1,r,u,v,value);
      ST[id].val=max(ST[2*id].val,ST[2*id+1].val);
}

int Get_Max(int id,int l,int r,int u,int v)
{
    down(id,l,r);
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return ST[id].val;
    int mid=(l+r)>>1;
    return max(Get_Max(2*id,l,mid,u,v),Get_Max(2*id+1,mid+1,r,u,v));
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>s>>q;
    while (q--)
    {
       int x,y,k;
       cin>>x>>y>>k;
       if (Get_Max(1,0,n,x,y)+k<=s)
       {
           cout<<1<<'\n';
           update(1,0,n,x,y-1,k);
       }
       else cout<<0<<'\n';

    }
    return 0;
}
