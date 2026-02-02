#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
/*
* 1561번
* 1. 일단 이분 탐색을 통해 뭘 도출해내야할지 부터 막막했음 -> 마지막 아이가 타는 시간을 도출해내야했음
* 2. 그런 후에 마지막 타는 시간 전까지 몇명의 아이들이 탔는지 계산을 진행
* 3. 그 이후에 현재 가용 가능한 놀이기구를 탐색하면서 마지막 아이의 번호에 해당하는지를 확인하는 방향이었음
* 
* 실수 포인트
* 1. 맨 마지막에 present_cnt == n이라고 해야하는데 present_cnt == (해당 시간에 탄 아이의 마지막 번호 -> 501로 입력했는데 505로 들어가는 등)
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

