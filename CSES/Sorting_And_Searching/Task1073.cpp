#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> lis;
	int x;
	cin >> x;
	lis.push_back(x);
	for (int i =1; i < n; i++){
		cin >> x;
		auto it = upper_bound(lis.begin(),lis.end(),x);
		if (it == lis.end()){
			lis.push_back(x);
		}
		else *it = x;
	}
	cout << lis.size();
	return 0;
}
