//chua xog 
#include<bits/stdc++.h>
#define N int(1e5)+5
using namespace  std
typedef long double ld;
int dx[] = {0,-1,-,1,-1,0,1,1,1},
    dy[] = {1,1,0,-1,-1,-1,0,1};
int X[N] = {0}, Y[N] = {0}, h[N], Xf, Yf;

ld Dis(ld x1,ld y1, ls x2,ld y2){
    return sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2));
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> Xm >> Ym >> Xf >> Yf;
    cin >> n;

    h[0] = 0;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        h[i] = (h[i-1]+x-'0')%7;
        X[i] = X[i-1]+dx[h[i]];
        Y[i] = Y[i-1]+dy[h[i]];
    }



    return 0;
}
