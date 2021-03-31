#include <bits/stdc++.h>
using namespace std;
int x, n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> n;
	vector<int> p(n);
	for (int &pi: p) cin >> pi;

	set<int> point;
	multiset<int> len;

	point.insert(0);
	point.insert(x);

	len.insert(x);

	for (int pi: p){
		auto itr = point.lower_bound(pi);
		auto itl = prev(itr);
		//cout << *itr << ' ' << *itl << '\n';

		len.erase(len.find((*itr) - (*itl)));
	       	point.insert(pi);
		len.insert(pi - (*itl));
		len.insert((*itr) - pi);
		cout << *prev(len.end()) << '\n';	
	}
	return 0;
}
