#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+7;
ll ans[N],a[N];
int n=0;
string s;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    string t="";
    for(int i=0; i<s.size(); i++){
        if (s[i]=='a' || s[i]=='b') t+=s[i];
    }

    for(int i=0; i<t.size(); ){
        if (t[i]=='b'){
            i++;
            continue;
        }
        int j=i;
        while (j<t.size() && t[j]=='a') j++;
        if (j>i){
            a[++n]=j-i;
        }
        i=j;
    }

    for(int i=1; i<=n; i++)
        ans[i]=((ans[i-1]*(ll)(a[i]+1))%Mod+a[i])%Mod;
    cout<<ans[n];
    return 0;
}
