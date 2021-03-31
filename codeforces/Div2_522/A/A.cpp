#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt[105]={0},n,k;
int maxx,d=0;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    for (int i=1; i<=100; i++)
    if (cnt[i]>0){
        maxx=max(maxx,cnt[i]);
        d++;
    }
    int tmp=(maxx/k)+(maxx%k ? 1:0);
    cout<<d*tmp*k-n;
    return 0;
}
