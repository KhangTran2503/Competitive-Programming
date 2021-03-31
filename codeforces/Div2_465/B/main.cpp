#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
char kt[N];
int n,res=0,x,y;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n; i++)
    {
        char c;
        cin>>c;
        kt[i]=c;
    }
    if (n>=3)
    {
        if (kt[1]=='U') y++;
        else x++;
        for(int i=2; i<n; i++)
        {
            if (kt[i]=='U') y++;
            else x++;
            if (x==y)
            {
                int xx1,yy1,xx2,yy2;
                xx2=xx1=x; yy2=yy1=y;
                if (kt[i+1]=='U') yy2++;
                else xx2++;
                if (kt[i]=='U') yy1--;
                else xx1--;
                if ((xx1<yy1 && xx2>yy2) || (xx1>yy1 && xx2<yy2)) res++;
            }
        }
    }
    cout<<res;
    return 0;
}
