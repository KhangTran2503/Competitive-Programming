#include<bits/stdc++.h>
using namespace std;
int check,n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    check=1;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x==1) check=0;
    }
    if (!check) cout<<"HARD";
    else cout<<"EASY";
    return 0;
}
