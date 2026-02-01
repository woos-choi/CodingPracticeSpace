#include <string>
#include <climits>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
/*

*/

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, c; cin >> s >> c;

	vector <long long> v;
	long long left = 1, right, sum = 0;
	for (int i = 0; i < s; i++) {
		long long temp; cin >> temp;
		v.push_back(temp);
		right = max(right, temp);
		sum += temp;
	}

	//right -= 1;

	long long mid, result = LLONG_MAX;
	while (left <= right) {
		mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / mid;
		}

		if (cnt >= c) {
			//cout << "통과  mid : " << mid << " 갯수 : " << cnt << " 라면에 넣을 파 : " << sum - c * mid << '\n';
			left = mid + 1;
			result = min(result, sum - c * mid);
		}

		else right = mid - 1;
	}

	cout << result;
	
}

