#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 2110. 공유기 설치 문제
* 이분 탐색 문제
* 한집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 함
* c개의 공유기를 N개의 집에 설치, 가장 인접한 두 공유기 사이의 거리를 최대로 하여라
* 근데 거리를 아무리 길게 해도,, 설치 가능한가? 를 먼저 살펴봐야 하잖아
* 설치를 v[0]부터 해도 상관없다 -> c개 이상 설치가 가능한지를 살펴보는 거니까 그리디하게 가도 상관없다
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c; cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int left = 1, right = v[n - 1] - v[0];

	int middle, result = -1;
	while (left <= right) {
		int cnt = 1;
		int temp = v[0];
		middle = (left + right) / 2;
		//cout << "present middle : " << middle << "---\n";

		for (int i = 1; i < v.size(); i++) {
			if (v[i] - temp >= middle) {
				//cout << temp << " / " << v[i] << " ";
				cnt++;
				temp = v[i];
				//cout << "change temp : " << temp << '\n';
			}
		}

		//cout << cnt << " ";

		if (cnt >= c) {
			left = middle + 1;
			result = max(result, middle);
		}

		else {
			right = middle - 1;
		}
	}

	cout << result;
}