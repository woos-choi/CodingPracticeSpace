#include <string>
#include <climits>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	/*
	* 1072 : 게임
	* 
	*/

	long long x, y; cin >> x >> y;
	long long init_result = (y * 100) / x;
	
	long long left = 1, right = 12345678900LL;
	long long result = LLONG_MAX;

	while (left <= right) {
		long long mid = (left + right) / 2;
		
		long long temp = ((y + mid) * 100) / (x + mid);
		if (temp > init_result) {
			right = mid - 1;
			result = min(result, mid);
		}

		else {
			left = mid + 1;
		}
	}

	if (result == LLONG_MAX) cout << -1;
	else cout << result;
	
}

