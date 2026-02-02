#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
/*
* 1561번
*/

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	vector<long long> v;

	long long left = 1, right = 60000000000;
	for (int i = 0; i < m; i++) {
		long long temp; cin >> temp;
		v.push_back(temp);
	}

	if (n <= m) cout << n;
	else {
		long long mid, result = right;
		while (left <= right) {
			mid = (left + right) / 2;

			//mid는 현재 시간이 언제인지를 담음
			long long temp_time = m;
			for (int i = 0; i < v.size(); i++) {
				temp_time += mid / v[i];
			}

			if (temp_time >= n) {
				right = mid - 1;
				result = min(result, mid);
			}

			else left = mid + 1;
		}

		long long present_cnt = m;
		for (int i = 0; i < v.size(); i++) {
			present_cnt += (result - 1) / v[i];
		}

		for (int i = 0; i < v.size(); i++) {
			if (result % v[i] != 0) continue;
			else {
				present_cnt++;
				if (present_cnt == n) {
					cout << i + 1;
					break;
				}
			}
		}
	}
	
}

