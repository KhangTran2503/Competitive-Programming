#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int n;
char a[N];
int l[N],r[N],len=0,G=0;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if (a[i]=='G'){
            l[i]=l[i-1]+1;
            G++;
        }
        len=max(len,l[i]);
    }

    for(int i=n; i>=1; i--)
        if (a[i]=='G') r[i]=r[i+1]+1;

    int res=len;
    for(int i=1; i<=n; i++)
       if (a[i]=='S') res=max(res,l[i-1]+r[i+1]+1);
    cout<<min(res,G);
    //cout<<res;
    return 0;
}
