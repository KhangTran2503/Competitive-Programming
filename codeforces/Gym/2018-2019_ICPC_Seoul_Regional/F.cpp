/*	2020-12-02	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
vector<int> num;
string tmp, s;

bool check1(string t){
	num.resize(t.size());
	int n  = (int)t.size();
	for (int i = 0; i < (int)t.size(); i++){
		if (isalpha(t[i])){
			num[i] = 0;
			continue;
		}
		if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '%' || t[i] == '/'){
			num[i] = 1;
			continue;
		}
		if (t[i] == '('){
			num[i] = 2;
			continue;
		}
		num[i] = 3;
	}
	if (n == 1 && num[0] == 0) return true;
	if (num[0] == 1 || num[n - 1] == 1) return false;
	if (num[0] == 3 || num[n - 1] == 2) return false;
	for (int i = 1; i < n; i++){
		if (num[i - 1] == 0 && num[i] == 0) return false; // aa
		if (num[i - 1] == 1 && num[i] == 1) return false; // ++
		if (num[i - 1] == 2 && num[i] == 3) return false; // ()
		if (num[i - 1] == 3 && num[i] == 2) return false; // )(
		if (num[i - 1] == 2 && num[i] == 1) return false; // (+
		if (num[i - 1] == 1 && num[i] == 3) return false; // +)
		if (num[i - 1] == 3 && num[i] == 0) return false; // )a
		if (num[i - 1] == 0 && num[i] == 2) return false; // a(
	}
	
	int sym = 0;
	for (int i = 0; i < n; i++){
		if (num[i] == 2) sym++;
		else if (num[i] == 3){
			if (sym == 0) return false;
			else sym--;
		}
	}
	return (sym == 0);
}

bool check2(string t){
	int n = t.size();
	stack<char> st;
	int sym = 0;
	int sum = 0;
	if (n == 1 && num[0] == 0) return true;
	for (int i = 0; i < n; i++){
		if (num[i] == 0) continue;
		if (num[i] == 1) sym++;
		if (num[i] == 3){
			int in_sym = 0;
			while (!st.empty()){
				char x = st.top();
				st.pop();
				if (x == '(') break;
				else in_sym++; 
			}
			if (in_sym != 1) return false;
			else sum++; 
		}
		else st.push(t[i]);
	}
	return (sum == sym - 1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	getline(cin,tmp);
	for (char x: tmp)
		if (x != ' ') s.push_back(x);
	
	//cout << s << '\n';
	if (check1(s)){
		if (check2(s)) cout << "proper";
		else cout << "improper";
	} 
	else cout << "error";
	return 0;
}