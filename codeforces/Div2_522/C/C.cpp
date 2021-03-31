///goi f[i][j] la do dai lon nhat khi 1->i thoa dk de bai
#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int a[N],f[N][6],n,Tr[1000100];

int id(int x,int y){
    return x*10+y;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=5; i++) f[1][i]=1;
    for(int i=2; i<=n; i++){
        if (a[i]==a[i-1]){
            for (int j=1; j<=5; j++){
                int Maxx=0;
                int idmax;
                for(int k=1; k<=5; k++)
                    if (j!=k)
                    if (f[i-1][k]>Maxx){
                        Maxx=f[i-1][k];
                        idmax=k;
                    }
                f[i][j]=Maxx+1;
                Tr[id(i,j)]=id(i-1,idmax);
            }
        }
        if (a[i]>a[i-1]){
            for (int j=1; j<=5; j++){
                int Maxx=0;
                int idmax;
                for(int k=1; k<j; k++)
                    if (f[i-1][k]>Maxx){
                        Maxx=f[i-1][k];
                        idmax=k;
                    }
                f[i][j]=Maxx+1;
                Tr[id(i,j)]=id(i-1,idmax);
            }
        }
        if (a[i]<a[i-1]){
            for (int j=1; j<=5; j++){
                int Maxx=0;
                int idmax;
                for(int k=j+1; k<=5; k++)
                    if (f[i-1][k]>Maxx){
                        Maxx=f[i-1][k];
                        idmax=k;
                    }
                f[i][j]=Maxx+1;
                Tr[id(i,j)]=id(i-1,idmax);
            }
        }
    }

    bool ok=false;
    int idmax=0;
    for(int i=1; i<=5; i++)
        if (f[n][i]==n) {
                ok=true;
                idmax=i;
        }

    if (ok) {
        vector<int> ans;
        int u=id(n,idmax);
        while (u>0){
            ans.push_back(u);
            u=Tr[u];
        }
        for(int i=n-1; i>=0; i--) cout<<ans[i]%10<<' ';

    }
    else cout<<-1;
    return 0;
}
