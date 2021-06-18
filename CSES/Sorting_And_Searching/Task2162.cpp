#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> nxt;
vector<int> prv;

void remove(int pos){
    int u = prv[pos];
    int v = nxt[pos];
    nxt[u] = v;
    prv[v] = u;

}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	nxt.resize(n + 1);
	prv.resize(n + 1);

	nxt[n] = 1;
	prv[1] = n;
	for (int i = 1; i < n; i++) nxt[i] = i + 1;
	for (int i = 2; i <= n; i++) prv[i] = i - 1;
	if (n > 1){
		int head = 2;
		int last;
		vector<int> visited(n + 1,0);
		while (1){
			cout << head << ' ';
			remove(head);
			visited[head] = -1;
			int next2 = nxt[nxt[head]];
			if (visited[next2] == -1){
				break;
			}
			head = next2;
		}
	}
	else cout << 1;
	return 0;
}
