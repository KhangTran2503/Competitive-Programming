#include <bits/stdc++.h>
using namespace std;
int n,ax,ay,bx,by,cx,cy;
int main()
{
    //cout << "Hello world!" << endl;
    cin>>n;
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;
    if ((bx-ax)*(cx-ax)>0 && (by-ay)*(cy-ay)>0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
