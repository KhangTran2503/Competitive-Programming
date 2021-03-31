#include <bits/stdc++.h>
using namespace std;
string ct ="bcdfghjklmnpqrstvxz";
string s;
int f[20][20] = {0};
int n;

int getbit(int state,int k){ return (state >> k) &1;}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> s;
    n = s.size();
    vector<int> flag(n);
    for (int i = 0; i < n; i++){
        int id = ct.find(s[i]);
        if (id != string::npos) flag[i] = id;
        else flag[i] = -1;
    }

    for (int i = 1; i < n; i++)
        if (flag[i - 1] >= 0 && flag[i] >= 0){
            f[flag[i - 1]][flag[i]] ++;
            f[flag[i]][flag[i - 1]] = f[flag[i - 1]][flag[i]];
        }

    int mask = (1 << 19) - 1;
    int maxmask = 0;
    int ans = 0;
    for (int msk = 1; msk < mask; msk ++){
        int t = 0;
        for (int i = 0; i < 19; i++)
            for (int j = 0; j < 19; j++){
                int tmp = (getbit(msk,i) == 1) + (getbit(msk,j) == 1);
                if (tmp == 1) t += f[i][j];
            }
        if (t > ans){
            ans = t;
            maxmask = msk;
        }
    }

    vector<int> u(19,0);
    for (int i = 0; i < 19; i++) u[i] = getbit(maxmask,i);
    //for (int i = 0; i < 19; i++) cout << u[i] << ' ';
    for (int i = 0; i < n; i++)
        if ( u[flag[i]]) s[i] = char((int(s[i]) - 32));
    cout << s;
}
