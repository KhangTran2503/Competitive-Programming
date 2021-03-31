#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> S;
vector<string> S_n_1;
vector<char> ans;

bool check(string a, string b){
    if (a.size() == 1) return true;
    string pre = a.erase(0,1);
    string suf = b.erase(b.size()-1,1);
    return (a == b);
}

void Solve(string a, string b){
    string Ss = a+b[b.size()-1];
    multiset<string> pre,suf;
    string t1="", t2="";
    for(int i=0; i<Ss.size()-1; i++){
        t1+=Ss[i];
        pre.insert(t1);
        t2=Ss[n-1-i]+t2;
        suf.insert(t2);
    }

    for (string x:S){
        if (pre.find(x)!=pre.end()){
            ans.push_back('P');
            pre.erase(x);

            continue;
        }
        if (suf.find(x)!=suf.end()){
            ans.push_back('S');
            suf.erase(x);
        }

    }

}

bool check1(vector<char> t){
    if (t.size() != 2*n-2) return false;
    int p = 0,s = 0;
    for (char x: t){
        if (x == 'P') p++;
        if (x == 'S') s++;
    }
    return (p == s && p == n-1);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int T = 1; T <= 2*n-2; T++){
        string x;
        cin >> x;
        S.push_back(x);
        if (x.size() == n-1) S_n_1.push_back(x);

    }

     if (check(S_n_1[0],S_n_1[1])) {
        Solve(S_n_1[0],S_n_1[1]);
        if (check1(ans)){
            for (char x: ans) cout << x;
            return 0;
        }
    }
    if (check(S_n_1[1],S_n_1[0])) {
        ans.clear();
        Solve(S_n_1[1],S_n_1[0]);
        if (check1(ans))
            for (char x: ans) cout << x;
    }
    return 0;
}
