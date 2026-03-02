#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<long long> v(n);

	long long sum = 0;
	long long max_result = -1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		max_result = max(max_result, v[i]);
	}

	long long k; cin >> k;

	if (sum <= k) {
		cout << max_result;
	}

	else {
		long long left = 1, right = max_result;

		long long middle, result = -1;
		while (left <= right) {
			middle = (left + right) / 2;
			long long temp = 0;

			for (int i = 0; i < n; i++) {
				if (v[i] - middle < 0) temp += v[i];
				else temp += middle;
			}

			if (temp <= k) {
				left = middle + 1;
				result = max(result, middle);
			}

			else {
				right = middle - 1;
			}
		}

		cout << result;
	}
	


}