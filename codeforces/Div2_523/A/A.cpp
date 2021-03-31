#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int s,n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>s;
    int res=0;
    for(int i=n; i>=1; i--){
            if (s>=i) {
            res+=s/i;
            s-=(s/i)*i;
        }
        if (s==0) break;
    }
    cout<<res;
    return 0;
}
