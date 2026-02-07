#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string str; cin >> str;
	int cnt = 0;
	stack<char> s;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			if (!s.empty()) s.pop();
			else cnt++;
		}
	}

	cnt += s.size();
	cout << cnt;
}