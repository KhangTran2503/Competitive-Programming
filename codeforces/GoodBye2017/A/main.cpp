#include <bits/stdc++.h>
#define N 100
#define Fi "vao.inp"
#define Fo "ra.out"
using namespace std;
char a[N];
int n,na,le;

int main()
{
    //freopen(Fi,"r",stdin);
    scanf("%s",a+1);n=strlen(a+1);
    for(int i=1; i<=n; i++)
    if('0'<= a[i]  &&  a[i]<='9')
    {
        int tg=a[i]-'0';
        if(tg%2)le++;
    }else
    {
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
            na++;
    }
    cout<<na+le;
    return 0;
}
