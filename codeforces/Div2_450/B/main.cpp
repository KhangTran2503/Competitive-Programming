#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b,c,dem;
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>a>>b>>c;
    bool ok=true;
    while (1)
    {
        dem++;
        if (dem>b) break;
        a*=10;
        int u=a/b;
        if (u==c)
        {
            ok=false;
            break;
        }
        a%=b;

    }
    if (!ok) cout<<dem;
    else cout<<-1;
    return 0;
}
