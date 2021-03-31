#include <iostream>
#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int t,n,maxx,res1,res2,s;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        s=0;
        res1=-oo;
        maxx=-oo;
        res2=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            if (s>0) s+=x;
            else s=x;
            res1=max(res1,s);

            maxx=max(x,maxx);
            if (x>0) res2+=x;
        }
        cout<<res1<<' ';
        if (res2==0) cout<<maxx<<'\n';
        else cout<<res2<<'\n';

    }

    return 0;
}
