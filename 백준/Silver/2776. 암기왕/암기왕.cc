#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
/*
* 2776번 암기왕
* 
*/

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		set<int> s;
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			s.insert(temp);
		}

		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int temp; cin >> temp;
			if (s.find(temp) != s.end()) cout << "1\n";
			else cout << "0\n";
		}
	}
	
}

