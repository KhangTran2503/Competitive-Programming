#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int> arr;

void init(){
    arr.resize(n + 1);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distr(0,1);
    for (int i = 1; i <= n; i++) arr[i] = distr(mt);
}


void ask(


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    

    return 0;
}
