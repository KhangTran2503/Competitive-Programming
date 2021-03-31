#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,pos,l,r;
int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d%d%d%d",&n,&pos,&l,&r);
    if (l==1 && r==n) printf("%d",0);
    else if (l==1) printf("%d",abs(pos-r)+1);
    else if (r==n) printf("%d",abs(pos-l)+1);
    else printf("%d",r-l+2+min(abs(pos-l),abs(pos-r)));

    return 0;
}
