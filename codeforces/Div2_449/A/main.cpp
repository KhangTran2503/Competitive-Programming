#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,l,r;
char c1,c2;
string s;

int main()
{
 //   cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    while (m--)
    {
        cin>>l>>r>>c1>>c2;
        for(int i=l-1; i<=r-1; i++)
           if (s[i]==c1) s[i]=c2;
    }
    cout<<s;
    return 0;
}
