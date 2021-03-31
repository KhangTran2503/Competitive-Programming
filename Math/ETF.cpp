#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e6) + 5;
vector<int> phi(Maxn);
vector<char> is_prime(Maxn,0);
int T;

void ETF(){
    
    for (int i = 1; i < Maxn; i++) phi[i] = i;

    for (int i = 2; i < Maxn; i++){
        if (!is_prime[i]){
            int j = i;
            while (j < Maxn){
                phi[j] -= phi[j]/i;
                is_prime[j] = 1;
                j += i;
            }
        }
    }   

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    ETF();
    while (T--){
        int n;
        cin >> n;
        cout << phi[n] << '\n';
    }
    return 0;
}