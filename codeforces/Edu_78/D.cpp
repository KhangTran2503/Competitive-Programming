#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<int> par;

int findset(int u){  return (u == par[u]) ? u : par[u] = findset(par[u]);}

bool Union(int u,int v){
    int U = findset(u);
    int V = findset(v);
    if (U == V) return false;
    par[U] = V;
    return true;
}

// sort L tang dan
// chat np tim R' lon nhat < R

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<ii> seg(n);
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;

    for (int i = 0; i < n; i++) cin >> seg[i].first >> seg[i].second;

    sort(seg.begin(),seg.end());
    
    map<int,int> save;

    for (int i = 0; i < n; i++){
        
        //if (it == save.end()) continue;
        for (auto it = save.lower_bound(-seg[i].second); it != save.end(); it++){
            int right = -(*it).first;
            if (right < seg[i].first) break;
            int v = (*it).second;
            if (!Union(i,v)){
                cout << "NO";
                return 0;
            }
            //else cout << i << ' ' << v << '\n';
        }
        save[-seg[i].second] = i;
    }

    int comp = 0;
    for (int i = 0; i < n; i++) comp += (par[i] == i);
    if (comp == 1) cout << "YES";
    else cout << "NO";
    return 0;
}