#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while(t--){
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        int res=int(2e9);
        if (abs(x-y)%d==0) {
            //cout<<abs(x-y)/d<<'\n';
            //continue;
            res=min(res,abs(x-y)/d);
        }
        if (abs(y-1)%d==0){
            res=min(res,(y-1)/d+(x-1)/d+(abs(x-1)%d!=0));
        }
        if (abs(n-y)%d==0) {
                res=min(res,abs(n-y)/d+(n-x)/d+(abs(n-x)%d!=0));
        }
        if(res==int(2e9)) cout<<-1<<'\n';
        else cout<<res<<'\n';
    }
    return 0;
}
