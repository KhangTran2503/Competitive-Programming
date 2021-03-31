#include <bits/stdc++.h>
using namespace std;
int cnt[]={0,0,4,4,4,4,4,4,4,4,16,4};
int sum=0,n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cnt[x]--;
        sum+=x;
    }
    if (sum>21) cout<<"STOP";
    else
    {
        for(int i=2; i<=11; i++)
            if (cnt[i]>0 && i<=21-sum)
        {
            cout<<"DRAW";
            return 0;
        }
        cout<<"STOP";
    }
    return 0;
}
