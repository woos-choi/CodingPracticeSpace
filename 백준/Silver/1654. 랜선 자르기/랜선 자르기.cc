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
	
	int k, n; cin >> k >> n;

	vector<long> v;
	long left = 1, right = -1;
	for (int i = 0; i < k; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
		if (right < temp) right = temp;
	}

	long mid, result = -1;

	while (left <= right) {
		//cout << "left : " << left << " right : " << right << '\n';
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / mid;
		}

		//cout << "cnt : " << cnt << '\n';
		
		if (cnt >= n) {
			left = mid + 1;
			if (result == -1) result = mid;
			else result = max(result, mid);
		}

		else right = mid - 1;
	}

	cout << result;
	
}