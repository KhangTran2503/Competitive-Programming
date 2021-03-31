#include <iostream>
#include <bits/stdc++.h>
#define Name "A"
using namespace std;
int v[4],vm;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    for (int i=1; i<=3; i++)
    {
        cin>>v[i];
    }

    cin>>vm;
    if (vm>2*v[3] ||vm>=v[2] || 2*vm<v[3])
    {
        cout<<-1;
    }
    else cout<<2*v[1]<<' '<<2*v[2]<<' '<<max(v[3],vm);

    return 0;
}
