#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int lower_bound(vector<int>& list,int data) {
	int left = 0, right = list.size() - 1;

	int mid, result = 10000001;
	while (left <= right) {
		mid = (left + right) / 2;
		if (list[mid] >= data) {
			right = mid - 1;
			result = min(result, mid);
		}

		else left = mid + 1;
	}

	return result;

}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//10 20 10 30 25 50

	vector<int> list;
	for (int i = 0; i < v.size(); i++) {
		if (list.size() == 0) {
			list.push_back(v[i]);
		}

		else {
			int index = lower_bound(list, v[i]);
			//cout << index << " ";
			if (index == 10000001) list.push_back(v[i]);
			else list[index] = v[i];
		}
	}

	cout << list.size();
	
}

