#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e7) + 5;
vector<int> prime(Maxn);


void init(){
   int sqrt_Maxn = sqrt(Maxn);
   for (int i = 2; i <= sqrt_Maxn; i++)
        if (prime[i] == 0)
            for (int j = i + i; j < Maxn; j += i) 
                if (prime[j] == 0) prime[j] = i;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    
    int T;
    cin >> T;
    set<int> s;
    while (T--){
        int L, R;
        cin >> L >> R;
        int u = L;
        while ((u > 1) && (prime[u] > 0)){
            s.insert(prime[u]);
            int p = prime[u];
            while (u % p == 0) u /= p;
        }
        if (u > 1) s.insert(u);

        u = R;
        while ((u > 1) && (prime[u] > 0)){
            s.insert(prime[u]);
            int p = prime[u];
            while (u % p == 0) u /= p;
        }
        if (u > 1) s.insert(u);
        cout << (int)s.size() << '\n';
        s.clear();
    }
    return 0;
}
