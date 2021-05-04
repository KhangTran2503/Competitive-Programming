#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<std::vector<int>> a;
vector<vector<int>> visit;
vector<vector<int>> ans;
vector<vector<int>> test;

int dx[] = {0,0,-1,1},
	dy[] = {-1,1,0,0};

int N, M;



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	a.resize(N,vector<int> (M,0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			cin >> a[i][j];
			

		}


	
	return 0;
}