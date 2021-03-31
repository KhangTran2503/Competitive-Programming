#include <bits/stdc++.h>
using namespace std;
int rmax,rmin,cmax,cmin,ccmin,ccmax,cpmin,cpmax;
int n,k,rq,cq;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    cin>>n>>k;
    cin>>rq>>cq;

    rmax=n+1; rmin=0; cmin=0; cmax=n+1;
    if (rq+cq<=n+1){
        cpmin=0;
        cpmax=rq+cq;
    }
    else{
        cpmax=n+1;
        cpmin=rq+cq-n-1;
    }

    if (rq-cq>=0){
        ccmax=n+1;
        ccmin=(rq-cq);
    }
    else{
        ccmin=0;
        ccmax=n+(rq-cq)+1;
    }
    while (k--){
        int u,v;
        cin>>u>>v;
        if (v==cq && u<rq) rmin=max(rmin,u);
        if (v==cq && u>rq) rmax=min(rmax,u);
        if (u==rq && v<cq) cmin=max(cmin,v);
        if (u==rq && v>cq) cmax=min(cmax,v);
        if (u+v==rq+cq && u<rq) cpmin=max(cpmin,u);
        if (u+v==rq+cq && u>rq) cpmax=min(cpmax,u);
        if (u-v==rq-cq && u<rq) ccmin=max(ccmin,u);
        if (u-v==rq-cq && u>rq) ccmax=min(ccmax,u);

    }
    int res=0;
    res=(rmax-rq)+(rq-rmin)+(cmax-cq)+(cq-cmin)+(rq-cpmin)+(cpmax-rq)+(rq-ccmin)+(ccmax-rq)-8;
    cout<<res;
    return 0;
}
