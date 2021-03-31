#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef pair<int,int> ii;
int vs[N],n,ans1=0,ans2=0;
ii a[N],b[N];


int main()
{
    //cout << "Hello world!" << endl;
    //freopen("Test.INP","r",stdin);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].first;
        b[n+1-i].first=a[i].first;
        a[i].second=i;
        b[i].second=i;
    }

    sort(a+1,a+1+n);///sort tim chu trinh
    for(int i=1; i<=n; i++){
        if (vs[i] || a[i].second == i) continue;///khi sort lai nhung vi tri can doi tao thanh
        int cycle=0;                            ///1 chu trinh khi do can doi toi da la cycle_size-1
        int j=i;
        while (!vs[j]){
            vs[j]=1;
            j=a[j].second;
            cycle++;
        }
        if (cycle>0) ans1+=(cycle-1);
    }
    sort(b+1,b+1+n);///tim mang nguoc
    memset(vs,0,sizeof(vs));
    for(int i=1; i<=n; i++){
        if (vs[i] || b[i].second == i) continue;
        int cycle=0;
        int j=i;
        while (!vs[j]){
            vs[j]=1;
            j=b[j].second;
            cycle++;
        }
        if (cycle>0) ans2+=(cycle-1);
    }

    cout<<min(ans1,ans2);

    return 0;
}
