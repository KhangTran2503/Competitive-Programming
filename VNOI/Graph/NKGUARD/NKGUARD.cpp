#include <iostream>
#include <bits/stdc++.h>
#define N 705
using namespace std;
typedef pair<int,int> ii;
int dx[]={-1,-1,-1,0,0,1,1,1},
    dy[]={-1,0,1,-1,1,-1,0,1};
int a[N][N],d[N][N]={0},mark[N*N];
int n,m,cnt=0;

bool inside(int u,int v){
    return (u>=1 && u<=n && v>=1 && v<=m);
}

void bfs(int u,int v){
    d[u][v]=cnt;
    queue<ii> q;
    q.push(ii(u,v));
    while(!q.empty()){
        int x=q.front().first,
            y=q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int xx=x+dx[i],
                yy=y+dy[i];
            if (inside(xx,yy) && !d[xx][yy] && a[xx][yy]==a[x][y]){
                q.push(ii(xx,yy));
                d[xx][yy]=cnt;
            }
        }

    }
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>a[i][j];

    memset(d,0,sizeof(d));
    for (int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if (!d[i][j]){
                ++cnt;
                bfs(i,j);
            }


    memset(mark,0,sizeof(mark));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            for(int k=0; k<8; k++){
                int x=i+dx[k],
                    y=j+dy[k];
                if (inside(x,y) && a[i][j]>a[x][y]) mark[d[x][y]]=1;
            }
        }

    int res=0;
    for(int i=1; i<=cnt; i++)
        if (mark[i]==0) res++;
    cout<<res<<'\n';

  /*  cout<<"--------------------------"<<'\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout<<d[i][j]<<' ';
        cout<<'\n';
    }*/
    return 0;
}
