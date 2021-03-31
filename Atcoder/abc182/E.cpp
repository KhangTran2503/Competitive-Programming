#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
vector<vector<int>> block_c, block_r, bulb_c, bulb_r;
int W, H, N, M;

bool check(int u,int v){
	//UP - DOWN
	if (binary_search(all(bulb_r[u]),v)) return true;
	if (binary_search(all(block_r[u]),v)) return false;
	
	if (!bulb_c[v].empty() && !block_c[v].empty()){
		auto nxt_bulb = lower_bound(all(bulb_c[v]),u);
		auto nxt_block = lower_bound(all(block_c[v]),u);
		if (nxt_bulb != bulb_c[v].end() && nxt_block != block_c[v].end()){
			if (*nxt_bulb < *nxt_block) return true;
		}
		else if (nxt_bulb != bulb_c[v].end()) return true;
		
		if (nxt_bulb != bulb_c[v].begin() && nxt_block != block_c[v].begin()){
			nxt_bulb--;
			nxt_block--;
			if (*nxt_bulb > *nxt_block) return true;
		}
		else if (nxt_bulb != bulb_c[v].begin()) return true;
	}
	else if (!bulb_c[v].empty()) return true;
	
	//LEFT - RIGHT
	if (!bulb_r[u].empty() && !block_r[u].empty()){
		auto nxt_bulb = lower_bound(all(bulb_r[u]),v);
		auto nxt_block = lower_bound(all(block_r[u]),v);
		if (nxt_bulb != bulb_r[u].end() && nxt_block != block_r[u].end()){
			if (*nxt_bulb < *nxt_block) return true;
		}
		else if (nxt_bulb != bulb_r[u].end()) return true;
		
		if (nxt_bulb != bulb_r[u].begin() && nxt_block != block_r[u].begin()){
			nxt_bulb--;
			nxt_block--;
			if (*nxt_bulb > *nxt_block) return true;
		}
		else if (nxt_bulb != bulb_r[u].begin()) return true;
	}
	else if (!bulb_r[u].empty()) return true;
	
	return false;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> H >> W >> N >> M;
	//init
	block_r.resize(H);
	block_c.resize(W);
	bulb_r.resize(H);
	bulb_c.resize(W);
	
	for (int i = 0; i < N; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		bulb_r[u].emplace_back(v);
		bulb_c[v].emplace_back(u);
	}
	
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		block_r[u].emplace_back(v);
		block_c[v].emplace_back(u);
	}
	
	for (int i = 0; i < H; i++){
		if (!bulb_r[i].empty()) sort(all(bulb_r[i]));
		if (!block_r[i].empty()) sort(all(block_r[i]));
	}
	
	for (int i = 0; i < W; i++){
		if (!bulb_c[i].empty()) sort(all(bulb_c[i]));
		if (!block_c[i].empty()) sort(all(block_c[i]));
	}
	
	int ans = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (check(i,j)){
				//cout << i << ' ' << j << '\n';
				ans += 1;
			}
			//ans += (int)check(i,j);
	
	cout << ans;
	return 0;
}
