#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int> f;

int calc(ll u){

    if (u==1) return 1;
    if (f.count(u)) return f[u];
    if (u%2==1) return f[u]=2+calc((3*u+1)/2);
    else return f[u]=1+calc(u/2);
  /*  int cnt=1;
    while(u>1){
        if (u%2==1){
            cnt+=2;
            u=(3*u+1)/2;
        }
        else {
            cnt++;
            u/=2;
        }
    }
    return cnt;*/
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int res=0,r1;
    for(int i=1000000;i>=1;i--){
        int tmp=calc((ll)(i));
        if (res<tmp){
            r1=i;
            res=tmp;
        }
    }
    cout<<r1;
    return 0;
}
