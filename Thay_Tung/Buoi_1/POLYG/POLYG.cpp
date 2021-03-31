///tinh dien tich da giac

#include <bits/stdc++.h>
#define db double
using namespace std;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<db> x(n+1),y(n+1);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    x[n]=x[0]; y[n]=y[0];

    db s=0;
    for(int i=0; i<n; i++)
         s+=(x[i]*y[i+1]-x[i+1]*y[i]);
    s=fabs(s)/2;
    cout<<fixed<<setprecision(6)<<s;
    return 0;
}
