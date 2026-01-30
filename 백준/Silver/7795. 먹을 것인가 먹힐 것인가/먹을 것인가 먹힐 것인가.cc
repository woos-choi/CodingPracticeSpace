#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		
		int cnt = 0;

		vector<int> v1;
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			v1.push_back(temp);
		}

		vector<int> v2;
		for (int i = 0; i < m; i++) {
			int temp; cin >> temp;
			v2.push_back(temp);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v1[i] > v2[j]) cnt++;
			}
		}

		cout << cnt << '\n';

	}

	
}