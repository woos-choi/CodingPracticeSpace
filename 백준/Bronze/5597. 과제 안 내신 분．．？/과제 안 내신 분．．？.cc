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

	set<int> s;
	for (int i = 1; i <= 30; i++) s.insert(i);

	for (int i = 0; i < 28; i++) {
		int data;
		cin >> data;
		s.erase(data);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << '\n';
}