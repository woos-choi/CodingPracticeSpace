#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int arr[10001] = { 0 };
	int min_index = 10001, max_index = -1;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int left, right;
		cin >> left >> right;

		for (int j = left; j < right; j++) arr[j] = 1;
		min_index = min(min_index, left);
		max_index = max(max_index, right);
	}

	int cnt = 0;
	for (int i = min_index; i < max_index; i++) {
		if (arr[i] == 1) cnt++;
	}

	cout << cnt;
	
}