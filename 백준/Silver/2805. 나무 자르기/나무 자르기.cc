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
		
	int n, m; cin >> n >> m;

	vector<long> v;
	long left = 1, right;

	for (int i = 0; i < n; i++) {
		long temp; cin >> temp;
		v.push_back(temp);
		right = max(right, temp);
	}

	long result = 0, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		
		long long int sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] - mid > 0) sum += v[i] - mid;
		}

		if (sum >= m) {
			left = mid + 1;
			result = max(result, mid);
		}

		else right = mid - 1;
	}

	
	cout << result;
}