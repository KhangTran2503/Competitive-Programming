#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e6) + 5;
vector<unordered_map<int,int>> divi(Maxn);

void Init(){
    divi[1].insert({1,0});
    vector<bool> is_prime(Maxn,0);
    for (int i = 2; i < Maxn; i++)
        if (!is_prime[i]){
            for (int j = i; j < Maxn; j += i){
                int u = j;
                int cnt = 0;
                while (u % i == 0){
                    u /= i;
                    cnt++;
                }
                divi[j].insert({i,cnt});
               is_prime[j] = 1;
            }
        }
}


int solve(int a,int b){
    int diff = 0;
    // in a
    for (auto it: divi[a])
        diff += abs(it.second - divi[b][it.first]);
    // in b
    for (auto it: divi[b])
        if (divi[a].find(it.first) == divi[a].end()) diff += it.second;
    return diff;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    Init();
    
    int a, b;
    while (cin >> a >> b){
        cout << solve(a,b) << '\n';
        //break;
    }    
    return 0;
}
