#include <bits/stdc++.h>
#define db double
using namespace std;
int pos,nega,zero,n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    int x;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if (x<0) nega++;
        if (x>0) pos++;
        if (x==0) zero++;
    }
    double res1=(db)pos/n;
    db res2=(db)nega/n;
    db res3=(db)zero/n;
    cout<<fixed<<setprecision(6)<<res1<<'\n';
    cout<<fixed<<setprecision(6)<<res2<<'\n';
    cout<<fixed<<setprecision(6)<<res3;
    return 0;
}
