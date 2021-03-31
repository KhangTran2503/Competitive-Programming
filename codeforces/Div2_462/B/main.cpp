#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>k;
    if (k>2*18) cout<<-1;
    else
    if (k==0) cout<<1;
    else
    {
        if (k&1) cout<<9;
        for(int i=1; i<=k/2; i++) cout<<8;
    }
    return 0;
}
