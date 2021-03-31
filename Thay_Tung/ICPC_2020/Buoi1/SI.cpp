#include <bits/stdc++.h>
using namespace std;
string s;
map<string,int> SI;



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	SI["tera"] = 12;
	SI["giga"] = 9;
	SI["mega"] = 6;
	SI["kilo"] = 3;
	SI["deci"] = -1;
	SI["centi"] = -2;
	SI["milli"] = -3;
	SI["micro"] = -6;
	SI["nano"] = -9;
	SI["meter"] = 1;
	SI["meter^2"] = 2;
	SI["meter^3"] = 3;
	
	int sum = 0;
	for (int i = 0; i < (int)s.size(); ){
		int j = i + 4;
		string t;
		if (j <= (int)s.size()){
			t = s.substr(i,4);
			//cout << t << '\n';
			if (SI.find(t) != SI.end()) {
				sum += SI[t];
				i = j;
				continue;
			}
		}
		j = i + 5;
		t = s.substr(i,5);
		if (t != "meter"){
			//cout << t << '\n';
			if (SI.find(t) != SI.end()) {
				sum += SI[t];
				i = j;
				continue;
			}
		}
		
		t = s.substr(i,s.size() - i);
		//cout << t << '\n';
		sum *= SI[t];
		break;
		
	} 
	cout << sum;
	return 0;
}
