#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l; cin >> n >> l;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string data; cin >> data;
		v.push_back(data);
	}

	sort(v.begin(), v.end());
	cout << v[l - 1];

}