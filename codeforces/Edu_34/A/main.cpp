#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

bool check(int x)
{
    for(int i=0; i<=100; i++)
      for(int j=0; j<=100; j++)
         if (3*i+7*j==x) return true;
    return false;

}
//========================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (check(x)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
