#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v(n);
	vector<int> cnt(n, 1);
	vector<int> prev_list(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = 1, index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			//maxValue를 응용을 한거다..
			if (v[j] < v[i] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if (result < cnt[i]) {
					result = cnt[i];
					index = i;
				}
			}
		}
	}

	vector<int> result_v;
	while (index >= 0) {
		result_v.push_back(v[index]);
		index = prev_list[index];
	}

	cout << result << '\n';
	//이걸 reverse로
	
	for (int i = result_v.size() - 1; i >= 0; i--) cout << result_v[i] << " ";
	
}

