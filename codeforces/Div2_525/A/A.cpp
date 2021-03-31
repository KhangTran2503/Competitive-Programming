#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int x;
    cin>>x;
    for (int b=1; b<=x; b++)
        for(int a=b; a<=x; a++)
           if (a*b>x && a%b==0 && a/b<x){
            cout<<a<<' '<<b;
            return 0;
           }
    cout<<-1;
    return 0;
}
