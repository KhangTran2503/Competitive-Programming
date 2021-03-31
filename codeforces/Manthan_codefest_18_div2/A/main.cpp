#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    cout<<int(log2(n))+1;
    return 0;
}
