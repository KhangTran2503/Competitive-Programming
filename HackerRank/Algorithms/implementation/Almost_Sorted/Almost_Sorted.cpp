///roi rac hoa
/// xu li tim doan lien tiep giam
/// nhung vi tri
#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int mp[1000005]={0},a[N],b[N],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    cin>>n;

    //vector<int> b;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+1+n);
    memset(mp,0,sizeof(mp));
    for(int i=1; i<=n; i++) mp[b[i]]=i;
    for(int i=1; i<=n; i++) a[i]=mp[a[i]];

    //for (int i=1; i<=10; i++) cout<<a[i]<<' ';
    int Wr=0;
    for(int i=1; i<=n; i++)
        if (a[i]!=i) Wr++;

    if (Wr==0) cout<<"yes"; ///so luong sai vt
    else if (Wr==2){
        cout<<"yes\n";
        cout<<"swap ";
        for(int i=1; i<=n; i++)
            if (a[i]!=i) cout<<i<<' ';
        }
        else {
            int correct=0;
            for(int i=1; i<=n; i++)
                if (a[i]==i) correct++;
                else break;

            for(int i=n; i>=1; i--)
                if (a[i]==i) correct++;
                else break;
            int curr=1,len=0;
            for(int i=2; i<=n; i++)
                if (a[i] < a[i-1]) curr++;
                else{
                    len=max(len,curr);
                    curr=1;
                }
            if (len+correct==n && len!=1){
                cout<<"yes\n";
                cout<<"reverse ";
                for(int i=1; i<=n; i++)
                    if (a[i]!=i){
                        cout<<i<<' ';
                        break;
                    }

                for(int i=n; i>=1; i--)
                    if (a[i]!=i){
                        cout<<i;
                        break;
                    }
            }
            else cout<<"no";
        }
    return 0;
}
