#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
struct Nodes
{
    int mod0,mod1,lazy;
    Nodes(){}
    Nodes(int m0,int m1,int la):mod0(m0),mod1(m1),lazy(la){}
};

Nodes ST[4*N];
int n,q;

void build(int id,int l,int r)
{
    if (l==r)
    {
        ST[id].mod0=1;
        ST[id].mod1=0;
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    ST[id].mod0=ST[2*id].mod0+ST[2*id+1].mod0;
    ST[id].mod1=ST[2*id].mod1+ST[2*id+1].mod1;
}


void down(int id,int l,int r)
{
    ST[id].lazy%=3;
    if (ST[id].lazy)
    {

        int mod0=ST[id].mod0;
        int mod1=ST[id].mod1;
        int mod2=(r-l+1)-mod0-mod1;
        if (ST[id].lazy==1)
        {
            ST[id].mod0=mod2;
            ST[id].mod1=mod0;
        }
        if (ST[id].lazy==2)
        {
            ST[id].mod0=mod1;
            ST[id].mod1=mod2;
        }
        if (l!=r)
         {
            ST[2*id].lazy+=ST[id].lazy;
            ST[2*id+1].lazy+=ST[id].lazy;
         }
        ST[id].lazy=0;
    }
}


void update(int id,int l,int r,int u,int v)
{
    down(id,l,r);
    if (r<u || l>v || l>r) return;
    if (u<=l && r<=v)
    {
        ST[id].lazy++;
        down(id,l,r);
        //ST[id].lazy=0;
        return;
    }
    int mid=(l+r)>>1;
    update(2*id,l,mid,u,v);
    update(2*id+1,mid+1,r,u,v);
    ST[id].mod0=ST[2*id].mod0+ST[2*id+1].mod0;
    ST[id].mod1=ST[2*id].mod1+ST[2*id+1].mod1;

}

int get(int id,int l,int r,int u,int v)
{
    down(id,l,r);
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return ST[id].mod0;
    int mid=(l+r)>>1;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>q;
    build(1,0,n-1);
    while(q--)
    {
        int k,A,B;
        cin>>k>>A>>B;
        if (k==0) update(1,0,n-1,A,B);
        else cout<<get(1,0,n-1,A,B)<<'\n';
    }
    return 0;
}
