#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;
int dx[]={-1,-1,-1,0,0,1,1,1},
    dy[]={-1,0,1,-1,1,-1,0,1};
int matrix[15][15];
int n,m;

bool inside(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m) return false;
    return true;
}
//==================================
int bfs(int x,int y)
{
    queue<ii> q;
    q.push(ii(x,y));
    matrix[x][y]=0;
    int res=0;
    while (!q.empty())
    {
        int u=q.front().f,
            v=q.front().s;
           q.pop();
            res++;
         for(int k=0; k<8; k++)
         {
            int uu=u+dx[k],
                vv=v+dy[k];
            if (inside(uu,vv) && matrix[uu][vv]==1)
            {
                q.push(ii(uu,vv));
                matrix[uu][vv]=0;
            }
         }
    }
    return res;

}
//================================================
int conectedCell()
{
    int res=0;
    for(int i=1; i<=n; i++)
       for(int  j=1; j<=m; j++)
         if (matrix[i][j]==1) res=max(res,bfs(i,j));

    return res;
}

//==============================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    cin>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>matrix[i][j];
    cout<<conectedCell();


    return 0;
}
