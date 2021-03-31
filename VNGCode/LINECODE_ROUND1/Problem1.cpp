/*	2021-01-11	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
map<string,string> dict;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++){
		string x;
		getline(cin,x);
		string t = x.substr(0,x.find_first_of(':'));
		//cout << t << '\n';
		dict[t] = x;
	}
	
	string x;
	getline(cin,x);
	//cout << x << '\n';
	auto it = dict.find(x);
	if (it == dict.end()) cout << "no data\n";
	else {
		for (int cnt = 0; it != dict.end() && cnt < 5; it++,cnt++) cout << (it->first) << '\n';
	}
	return 0;
}