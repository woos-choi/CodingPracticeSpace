#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
* 2343. 기타 레슨
* 블루레이 1개에 n개의 강의가 들어감, 순서가 바뀌면 안됨 (1번강의 4번강의를 담고 싶으면 1, 2, 3, 4를 담아라)
* 블루레이 m개는 주어짐, 블루레이 하나가 담을 length를 이분탐색으로 찾아야 함
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	int max_len;

	vector<int> v;
	int left = -1;
	long right = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
		
		left = max(left, temp);
		right += temp;
	}

	max_len = left;
	//cout << left << " " << right << '\n';

	int mid, result = 987654321;
	while (left <= right) {
		mid = (left + right) / 2;
		//cout << mid << " ";

		//이제 여기서 1개의 블루레이가 mid를 담을 수 있을 떄 vector에 있는 강의가 m개의 블루레이에 다 담길 수 있는지를 확인해야함
		//vector 순회를 어떻게 해야하는가

		int temp = mid, cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (temp - v[i] < 0) {
				cnt++;
				temp = mid;
				temp -= v[i];
			}

			else if (temp - v[i] == 0) {
				cnt++;
				temp = mid;
			}

			else {
				temp -= v[i];
			}
		}

		if (temp > 0 && temp != mid) cnt++;

		//cout << " cnt : " << cnt << " mid : " << mid << '\n';

		//cnt가 블루레이의 갯수보다 큰 경우 left를 갱신 (불가능), cnt가 블루레이의 갯수보다 작은 경우 right를 갱신 (불가능)
		if (cnt > m) {
			//cout << cnt  <<" 갯수가 너무 많습니다 : left 갱신" << '\n';
			left = mid + 1;
		}
		else if (cnt <= m) {
			//cout << cnt << " 갯수가 너무 적습니다 : right 갱신" << '\n';
			result = min(result, mid);
			right = mid - 1;
		}
	}

	//cout << result;
	if (result == 987654321) result = max_len;
	cout << result;
}