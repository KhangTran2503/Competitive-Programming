#include <bits/stdc++.h>
using namespace std;
vector<string> v;

int main() {
	int h1, a1, c1, h2, a2;
	cin >> h1 >> a1 >> c1;
	cin>> h2 >> a2;

	while (h2 > 0) {
		if (a1 >= h2) {
			v.push_back("STRIKE");
			break;
		}
		if (h1 > a2) {
			v.push_back( "STRIKE");
			h1 -= a2;
			h2 -= a1;
		}
		else {
			v.push_back("HEAL");
			h1 += c1-a2;
		}
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) cout<<v[i]<<'\n';
}
