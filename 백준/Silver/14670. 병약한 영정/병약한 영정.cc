#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int e, k; cin >> e >> k;
		m.insert({ e,k });
	}

	int r; cin >> r;
	for (int i = 0; i < r; i++) {
		int l; cin >> l;
		int flag = 0;

		vector<int> result;
		for (int j = 0; j < l; j++) {
			int data; cin >> data;
			if (m.find(data) != m.end()) result.push_back((*m.find(data)).second);
			
			else {
				flag = 1;
			}
		}

		if (flag == 0) {
			for (int j = 0; j < result.size(); j++) cout << result[j] << " ";
		}

		else cout << "YOU DIED";
		cout << '\n';
		
	}

}