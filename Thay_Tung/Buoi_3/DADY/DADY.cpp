#include <bits/stdc++.h>
#define Fi "vao.inp"
#define Fo "ra.out"
using namespace std;
int ans;
struct TreapNode
{
    int k,p;
    TreapNode *l, *r;
    TreapNode(int key, int value)
    {
        k = key;
        p =value;
        l = r = NULL;
    }
} ;
typedef TreapNode *pitem;
pitem t=nullptr;
pitem merge(pitem a, pitem b)
{
    if(!a || !b)
        return a ? a : b;
    if (a->p > b->p)
    {
        a->r = merge(a->r,b);
        return a;
    }else
    {
        b->l = merge(a,b->l);
        return b;
    }
}

void split(pitem t, int k, pitem &a, pitem &b)
{
    if(!t)
        a = b =NULL;
    else
        if(t->k <k)
        {
            split(t->r, k , t->r, b);
            a=t;
        }else
        {
            split(t->l, k ,a , t->l);
            b=t;
        }
}

void insert(int key, int value)
{
    pitem tn= new TreapNode(key, value), t1 , t2;
    split(t,key, t1, t2);
    t= merge(t1, tn);
    t= merge(t, t2);
}

void get_res(int y ,int b)
{
    pitem pr,t1,t2,t3,t4;
    split(t,b,t3,t4);
    t1=t3;t2=t4;
    if(t2==NULL || t2->p <-y)
    {
        ans=-1;
        t=merge(t3,t4);
        return;
    }
    ans = t2->k;
    while (t2 != NULL && t2->k >b)
    {
        t1=t2;
        t2=t2->l;
        if(t2!=NULL && t2->k >=b && t2->p >= -y)
        {
            ans=t2->k;
        }
    }
    t=merge(t3,t4);

}
int main()
{
    //freopen(Fi,"r",stdin);
    //freopen(Fo,"w",stdout);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int n,m,pr,x,y;
    char c;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> c >> x >> pr;
        if(c=='M') insert(pr,-x);
        else
        {
            get_res(x,pr);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
