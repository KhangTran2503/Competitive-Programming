#include<bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef unsigned long long ll;
ll a[N],b[N];
int n;


int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n/2; i++) cin>>b[i];
    a[1]=0; a[n]=b[1];
    for (int i=2; i<=n/2; i++)
        if (b[i]>a[n-i+2]) {
            a[i]=max(a[i-1],b[i]-a[n-i+2]);
            a[n-i+1]=b[i]-a[i];

        }
        else {
            a[n-i+1]=b[i]-a[i-1];
            a[i]=a[i-1];
        }
    for(int i=1; i<=n; i++) cout<<a[i]<<' ';
}
