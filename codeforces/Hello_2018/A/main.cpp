#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;

int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d",&n);
    scanf("%d",&m);
    if (n<=27) printf("%d",m%(1<<n));
    else printf("%d",m);
    return 0;
}
