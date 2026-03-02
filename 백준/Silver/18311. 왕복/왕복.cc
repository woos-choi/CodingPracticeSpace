#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k; cin >> n >> k;
	long long middle = 0;

	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		middle += v[i];
	}

	long long result = 1;
	int flag = 0;

	if (k == middle) result = n;
	else {

		//1. 일단 한번 순회를 하고
		for (int i = 0; i < v.size(); i++) {
			if (k - v[i] <= 0) {
				if (k - v[i] < 0) result = i + 1;
				else result = i + 2;
				flag = 1;
				break;
			}

			else k -= v[i];
		}

		//2. 순회를 했는데도 k>0인 경우에는 역 순회를 해보자
		if (flag == 0) {
			for (int i = v.size() - 1; i >= 0; i--) {
				if (k - v[i] <= 0) {
					if (k - v[i] < 0) result = i + 1;
					else result = i;
					break;
				}

				else k -= v[i];
			}
		}
	}

	cout << result;
	


}