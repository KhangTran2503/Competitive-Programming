#include <iostream>
#include <bits/stdc++.h>
#define Name "A"
using namespace std;
string s;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>s;
    if (s[s.size()-1]-'0'<=5)
    {
        s[s.size()-1]='0';
        cout<<s;
    }
    else
    {
        int c=1;
        int n=s.size()-1;
        s[n]='0';
        for(int i=n-1; i>=0; i--)
        {
            int so=s[i]-'0';
            int u=(so+c)%10;
            c=(so+c)/10;
            s[i]=u+'0';
        }
        if (c>0) s="1"+s;
        cout<<s;
    }
    return 0;
}
