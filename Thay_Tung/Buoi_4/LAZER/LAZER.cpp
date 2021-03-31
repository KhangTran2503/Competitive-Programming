#include <bits/stdc++.h>
#define N 3*int(1e5)+5
#define limit int(1e5)
using namespace std;
int e1[N]={0},e2[N]={0},e3[N]={0};
int n,t;
int64_t E;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int xx1,yy1,xx2,yy2;
        cin>>xx1>>yy1>>xx2>>yy2;
        xx1+=limit; xx2+=limit;
        int x1=xx1-yy1;
        int x2=xx2-yy1;
        int y2=yy2-yy1;
        int k=min(x2-x1,y2);

        e3[(x1-y2)+1]++; e3[(x1-y2)+1+k]--;
        e3[x2-(k-1)]--; e3[x2+1]++;

        x1=xx1+yy1; x2=xx2+yy1; y2=yy2-yy1;
        k=min(x2-x1,y2);
        e2[x1+1]++; e2[x1+1+k]--;
        e2[x2+y2-(k-1)]--; e2[x2+y2+1]++;

        e1[xx1]+=(yy2-yy1);
        e1[xx2+1]-=(yy2-yy1);
    }


    for(int i=1; i<N; i++)
    {
        e1[i]+=e1[i-1];
        e2[i]+=e2[i-1];
        e3[i]+=e3[i-1];
    }

    for(int i=1; i<N; i++)
    {
        e2[i]+=e2[i-1];
        e3[i]+=e3[i-1];
    }

    cin>>t;
    while (t--)
    {
        int x1,k;
        cin>>x1>>k;
        x1+=limit;
        E=0;
        switch (k)
        {
            case 1:E=(int64_t)e1[x1]*e1[x1]; break;
            case 2:E=(int64_t)2*e2[x1]*e2[x1]; break;
            case 3:E=(int64_t)2*e3[x1]*e3[x1]; break;
        }
        cout<<E<<'\n';
    }
    return 0;
}
