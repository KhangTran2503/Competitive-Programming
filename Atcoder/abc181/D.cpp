#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; 
	cin >> s;
	int cnt[10] = {};
	for (char& c : s) ++cnt[c - '0'];
	bool flag = false;
	if (s.size() < 3) {
		if (stoi(s) % 8 == 0) flag = true;
		reverse(s.begin(), s.end());
		if (stoi(s) % 8 == 0) flag = true;
	} else {
		for (int i = 100; i < 1000; ++i) {
			if (i % 8 == 0) {
				string t = to_string(i);
				int t_cnt[10] = {};
				for (char& c : t) ++t_cnt[c - '0'];
				bool f = true;
				for (int j = 0; j < 10; ++j)
					if (cnt[j] < t_cnt[j]) f = false;
				flag |= f;
			}
		}
	}
	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
