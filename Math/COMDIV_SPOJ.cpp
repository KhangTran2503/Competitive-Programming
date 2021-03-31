#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e6) + 5;
int cntdivi[Maxn] = {0};
int T;

void Era(){
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i) cntdivi[j]++;   
} 

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    Era();
    while (T--){
        int a, b;
        cin >> a >> b;
        cout << cntdivi[__gcd(a,b)] << '\n';
    }
    return 0;
}