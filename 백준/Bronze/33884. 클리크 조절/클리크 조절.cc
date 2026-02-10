#include <string>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else return false;
}

void print_vector(vector<pair<int, int>> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n; cin >> n;

	vector<pair<int, int>> first;
	vector<pair<int, int>> second;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		first.push_back({ x, y });
	}
	sort(first.begin(), first.end());
	//print_vector(first);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		second.push_back({ x, y });
	}
	sort(second.begin(), second.end());
	//print_vector(second);

	cout << second.front().first - first.front().first << " " << second.front().second - first.front().second;
}

