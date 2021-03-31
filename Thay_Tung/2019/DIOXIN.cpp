#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

static const int N = 1009, oo = int(1e9)+9;
//int col[N][4*N],row[N][4*N];
vector<vector<int>> col, row;
int n,m,query,x,y;
char ch;

void updatex(int idx,int id,int l,int r,int i)
{
    if (l > i|| r < i || l > r) return;
    if (l==r)
    {
        row[idx][id]=1;
        return;
    }
    int mid=((l+r) >> 1);
    updatex(idx ,2*id ,l ,mid, i);
    updatex(idx, 2*id+1, mid+1, r, i);
    row[idx][id]=min(row[idx][2*id],row[idx][2*id+1]);
}

void updatey(int idy,int id,int l,int r,int i)
{
    if (l > i|| r < i || l > r) return;
    if ( l == r){
        col[idy][id]=1;
        return;
    }
    int mid=((l+r) >> 1);
    updatey(idy,2*id,l,mid,i);
    updatey(idy,2*id+1,mid+1,r,i);
    col[idy][id] = min(col[idy][2*id],col[idy][2*id+1]);
}

int getminx(int idx,int id,int l,int r,int u,int v)
{
    if (l > v || r < u || l > r) return oo;
    if (u <= l && r <= v) return row[idx][id];
    int mid=(l+r)>>1;
    return min(getminx(idx,id*2,l,mid,u,v),getminx(idx,id*2+1,mid+1,r,u,v));
}

int getminy(int idy,int id,int l,int r,int u,int v)
{
    if (l > v || r < u || l > r) return oo;
    if (u <= l && r <= v) return col[idy][id];
    int mid=(l+r) >> 1;
    return min(getminy(idy,id*2,l,mid,u,v),getminy(idy,id*2+1,mid+1,r,u,v));
}

int calu(int x,int y)
{
    int l=0, r = x-1;
    int ret = -1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        //if (getminx(y,1,1,n,mid,mid)==0) ret=mid;
        if (getminy(y,1,0,n - 1,mid,x-1) == 0){
            ret = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if (ret == -1) //printf("%d\n",-1);
        cout << -1 << '\n';
    else //printf("%d %d\n",x,ret);
        cout << ret + 1 << ' ' << y + 1 << '\n';
}

int cald(int x,int y)
{
    int l = x+1, r = n - 1;
    int ret = -1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        //if (getminy(y,1,1,n,mid,mid)==0) ret=mid;
        if (getminy(y,1,0,n - 1,x + 1,mid) == 0){
            ret = mid;
            r = mid - 1;
        }
        else l = mid+1;
    }
    if (ret == -1) //printf("%d\n",-1);
        cout << -1 << '\n';
    else //printf("%d %d\n",x,ret);
        cout << ret + 1 << ' ' << y + 1 << '\n';
}

int calr(int x,int y)
{
    int l= y + 1 , r = m - 1;
    int ret = -1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        //if (getminx(y,1,1,n,mid,mid)==0) ret=mid;r
        if (getminx(x,1,0,m - 1,y + 1,mid) == 0){
            ret = mid;
            r = mid - 1;
        }
        else l = mid+1;
    }
    if (ret == -1) //printf("%d\n",-1);
        cout << -1 << '\n';
    else //printf("%d %d\n",x,ret);
        cout << x + 1 << ' ' << ret + 1 << '\n';
}

int call(int x,int y)
{
    int l= 0 , r = y - 1;
    int ret = -1;
    while (l <= r)
    {
        int mid=(l+r)>>1;
        //if (getminx(y,1,1,n,mid,mid)==0) ret=mid;r
        if (getminx(x,1,0,m - 1,mid,y - 1) == 0){
            ret = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if (ret == -1) //printf("%d\n",-1);
        cout << -1 << '\n';
    else //printf("%d %d\n",x,ret);
        cout << x + 1 << ' ' << ret + 1 << '\n';
}

int main()
{
    //scanf("%d%d%d",&n,&m,&query);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> query;
    int bqv_col = 1, bqv_row = 1;
    while(bqv_col < m) bqv_col <<=1;
    while(bqv_row < n) bqv_row <<=1;

    row.resize(n,vector<int>(bqv_col * 2));
    col.resize(m,vector<int>(bqv_row * 2));

    while (query--)
    {
        cin >> ch;
        if (ch =='c')
        {
            //scanf("%d%d",&x,&y);
            cin >> x >> y;
            x --, y --;
            updatex(x,1,0,m - 1,y);
            updatey(y,1,0,n - 1,x);
        }
        else
        {
            //scanf("%d%d",&x,&y);
            cin >> x >> y;
            x--, y--;
            switch (ch)
            {
            case 'u':
                {
                    //printf("%d\n",calu(x,y));
                    calu(x,y);
                    break;
                }
            case 'd':
                {
                    //printf("%d\n",cald(x,y));
                    cald(x,y);
                    break;
                }
            case 'l':
                {
                    //printf("%d\n",call(x,y));
                    call(x,y);
                    break;
                }
            case 'r':
                {
                    //printf("%d\n",calr(x,y));
                    calr(x,y);
                    break;
                }
            }
        }
    }
}
