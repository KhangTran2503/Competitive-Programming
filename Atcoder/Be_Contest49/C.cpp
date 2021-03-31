#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e6);
vector<bool> isprime(Maxn + 1,0);
int X;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> X;
    isprime[0] = isprime[1] = 1;
    for (int i = 2; i <= 1000; i++)
        if (!isprime[i])
            for (int j = i*i; j <= Maxn; j += i) isprime[j] = 1;
    
    while (X <= Maxn && isprime[X]) X++;
    cout << X;
    return 0;
}