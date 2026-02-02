#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
* 14003번. 가장 긴 증가하는 부분 수열
*/

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v;
	vector<int> cnt;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
		cnt.push_back(0);
	}

	int result = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		int maxValue = 0;
		for (int j = v.size() - 1; j > i; j--) {
			if (v[i] > v[j] && maxValue < cnt[j]) maxValue = cnt[j];
		}
		cnt[i] = maxValue + 1;
		result = max(result, cnt[i]);
	}

	//for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << " ";
	//cout << '\n';

	cout << result;
	
}

