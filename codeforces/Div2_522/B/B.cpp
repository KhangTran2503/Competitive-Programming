#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string ans[10];
string s;

void Print(int a,int b){
    cout<<a<<' '<<b<<'\n';
    for (int i=1; i<=a*b-n; i++) ans[i]+="*";
    int cnt=0;
    for (int i=1; i<=a; i++){
        while (ans[i].size()<b){
            ans[i]+=s[cnt++];
        }
    }
    for(int i=1; i<=a; i++) cout<<ans[i]<<'\n';

}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for (int a=1; a<=5; a++)
        for (int b=1; b<=20; b++)
            if (a*b>=n && a*b-n<=a){
                Print(a,b);
                return 0;
            }
    return 0;
}
