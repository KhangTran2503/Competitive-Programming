///Goi Maxx[i] la tong lon nhat cua subset 1->i ket thuc tai i
/// Maxx[i]=Max(Maxx[i-1],Maxx[i-2]+arr[i],arr[i])
#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int  arr[N],Maxx[N];
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];

    Maxx[1]=arr[1]; Maxx[2]=max(Maxx[1],arr[2]);
    for(int i=3; i<=n; i++)
    {
        Maxx[i]=max(Maxx[i-1],max(arr[i],Maxx[i-2]+arr[i]));
    }
    int  res=-int(1e9);
    for(int i=1; i<=n; i++) res=max(res,Maxx[i]);
    cout<<res;
    return 0;
}
