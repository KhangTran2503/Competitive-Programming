#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,x,y,X,Y;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    while (1)
    {
        cin>>t;
        if (t==0) break;
        cin>>X>>Y;
        while (t--)
        {
            cin>>x>>y;
            int u=x-X;
            int v=y-Y;
            if (u==0 || v==0) cout<<"divisa"<<'\n';
            if (u>0 && v>0) cout<<"NE"<<'\n';
            if (u>0 && v<0) cout<<"SE"<<'\n';
            if (u<0 && v>0) cout<<"NO"<<'\n';
            if (u<0 && v<0) cout<<"SO"<<'\n';
        }


    }
    return 0;
}
