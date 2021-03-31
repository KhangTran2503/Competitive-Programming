#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,res;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
        if (n%i==0) res++;
    cout<<res;
    return 0;
}
