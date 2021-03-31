#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int cnt[N],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    //int res=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
        //=max(res,cnt[x]);
    }
    for(int i=N; i>=1; i--)
    {
        if (cnt[i]&1)
        {
            cout<<"Conan";
            return 0;
        }
    }
    cout<<"Agasa";
    return 0;
}
