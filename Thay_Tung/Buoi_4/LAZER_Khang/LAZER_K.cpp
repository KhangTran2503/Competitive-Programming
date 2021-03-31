///Ung dung mang tien to
#include <bits/stdc++.h>
#define N 3*int(1e5)+5
#define limit int(1e5)
using namespace std;
int e2[N]={0},e3[N]={0},e1[N]={0};
int n,t;
int64_t E;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=limit;  y1+=limit; x2+=limit; y2+=limit;
        int k=min(x2-x1,y2-y1); ///xet truong hop theo chieu dung hoac nam ngang

        e1[x1]+=(y2-y1); e1[x2+1]-=(y2-y1);///laze theo chieu thang dung

        e3[x1-y2+1]++; e3[x1-y2+k+1]--;  ///laze theo chieu cheo 3
        e3[x1-y1-k+1]--; e3[x1-y1]++;

        e2[x1+y1+1]++; e2[x1+y1+k+1]--;   ///laze theo chieu cheo 2
        e2[x2+y2-k+1]-- ; e2[x2+y2+1]++;

    }

    for(int i=1; i<=N; i++)
    {
        e1[i]+=e1[i-1];
        e2[i]+=e2[i-1];
        e3[i]+=e3[i-1];
    }

    for(int i=1; i<=N; i++)
    {
        e2[i]+=e2[i-1];
        e3[i]+=e3[i-1];
    }

    cin>>t;
    while (t--)
    {
        int x,d;
        cin>>x>>d;
        x+=limit;
        switch (d) ///duong cheo nhan them cho 2
        {
            case 1:E=(int64_t)e1[x]*e1[x]; break;
            case 2:E=(int64_t)2*e2[x]*e2[x]; break;
            case 3:E=(int64_t)2*e3[x]*e3[x]; break;
        }
        cout<<E<<'\n';
    }
    return 0;
}
