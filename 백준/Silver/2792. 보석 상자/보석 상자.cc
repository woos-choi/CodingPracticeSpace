#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

bool check(vector<int>& v, int data) {
	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % data == 0) cnt += v[i] / data;
		else cnt += v[i] / data + 1;
	}

	if (cnt <= n) return true;
	else return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	vector<int> v;

	int left = 1, right = 0, mid;
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
		right = max(right, temp);
	}

	int result = 987654321;
	while (left <= right) {
		mid = (left + right) / 2;

		if (check(v, mid) == true) {
			result = min(result, mid);
			right = mid - 1;
		}

		else left = mid + 1;
	}

	cout << result;

}