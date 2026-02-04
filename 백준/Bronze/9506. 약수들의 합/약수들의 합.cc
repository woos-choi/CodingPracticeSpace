#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int n; cin >> n;
		if (n == -1) break;

		vector<int> v;
		int temp = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				temp += i;
				v.push_back(i);
			}
		}

		if (n == temp) {
			cout << n << " = ";
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " + ";
			}
			cout << v.back() << '\n';
		}

		else cout << n << " is NOT perfect.\n";

	}

}

