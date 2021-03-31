#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k,x,res=int(1e9);

int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if (k%x==0) res=min(res,k/x);
    }
    printf("%d",res);
    return 0;
}
