#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define INF (ll)(1e17)
const int Maxn = int(1e5) + 5;
using namespace std;
struct Node
{
    ll pre,sum,suf,ans;
    Node(){};
    Node(ll pr,ll su,ll sufi,ll an)
    {
        pre=pr;
        sum=su;
        suf=sufi;
        ans=an;
    }
} nodes[4*Maxn];
ll a[Maxn];
 
Node combine(Node l,Node r)
{
    Node par;
    par.sum=l.sum+r.sum;
    par.pre=max(l.pre,l.sum+r.pre);
    par.suf=max(r.suf,r.sum+l.suf);
    par.ans=max(max(l.ans,r.ans),l.suf+r.pre);
    return par;
}
//=============================================
void build(int id,int l,int r)
{

    if (l==r) nodes[id]=Node(a[l],a[l],a[l],a[l]);
    else
    {
        int mid=(l+r)>>1;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        nodes[id]=combine(nodes[2*id],nodes[2*id+1]);
    }
}

void update(int id,int l,int r,int pos,int val){
    if (pos < l || pos > r) return;
    if (l == r){
        nodes[id] = Node(val,val,val,val);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1,l,mid,pos,val);
    update((id << 1) | 1,mid + 1,r,pos,val);
    nodes[id] = combine(nodes[2*id],nodes[2*id + 1]);
}

//================================
Node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return Node(-INF,0,-INF,-INF);
    if (u<=l && r<=v) return nodes[id];
    else
    {
        int mid=(l+r)>>1;
        return combine(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
    }
}
//==================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= 4*n; i++) nodes[i] = Node(-INF,0,-INF,-INF);
        build(1,1,n);
        for (int i = 0; i < q; i++){
            char c;
            cin >> c;
            if (c == 'Q'){
                int x, y;
                cin >> x >> y;
                Node mid = get(1,1,n,x,y);
                Node lef = get(1,1,n,1,x - 1);
                Node rig = get(1,1,n,y + 1,n);
                ll ans = max(0LL,lef.suf) + mid.sum + max(0LL,rig.pre);
                cout << ans << '\n';
                //cout << '#' <<  lef.suf << ' ' << mid.sum << ' ' << rig.pre << '\n';
            }
            else {
                int x, y;
                cin >> x >> y;
                update(1,1,n,x,y);
            }
        }
    }
    return 0;
}
 