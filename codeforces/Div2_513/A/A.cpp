#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int d[15]={0};
int n;
string s;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<s.size(); i++)
      d[s[i]-'0']++;
    if (n<11)
    {
        cout<<0;
        return 0;
    }
    if (d[8]==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1; i<=d[8]+1; i++)
        if (n<i*11 || i==d[8]+1)
    {
        cout<<i-1;
        //return 0;
        break;
    }
    return 0;
}
