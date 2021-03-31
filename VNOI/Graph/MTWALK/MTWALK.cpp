#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1},
    dy[]={1,-1,0,0};
int d[105][105],a[105][105];
int n;

bool inside(int x,int y){
    return (x>0 && x<=n && y>0 && y<=n);
}

bool dfs(int u,int v,int Min,int Max){
    d[u][v]=1;
    if (u==n && v==n) return 1;
    int ok=0;
    for(int i=0; i<4; i++){
        int uu=u+dx[i], vv=v+dy[i];
        if (inside(uu,vv) && !d[uu][vv] && a[uu][vv]<=Max && a[uu][vv]>=Min){
                ok|=dfs(uu,vv,Min,Max);
        }
    }
    return ok;


}

bool check(int Min,int Max){
    memset(d,0,sizeof(d));
    return dfs(1,1,Min,Max);
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin>>a[i][j];

    int ans=int(1e9);
    for (int i=0; i<=a[1][1]; i++) ///Gia su Min=0->a[1][1] thu tung Min
    {                              ///Moi Min thi xet a[u][v]>=Min and a[u][v]<=Min+delta
        int l=0,r=110,res=int(1e9);///ton tai duong di cap nhat delta
        while (l <= r){
           int mid=(l+r)>>1;
           if (check(i,i+mid)){
               res=mid;
               r=mid-1;
           }
           else l=mid+1;
        }
        ans=min(ans,res);
    }
    //if (check(2)) cout<<2;
    cout<<ans;
    return 0;
}
