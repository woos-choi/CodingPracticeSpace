#include <iostream>
#include <sstream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b; cin >> a >> b;
	vector<vector<char>> v(n);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < m; j++) v[i].push_back('S');
	}

	for (int i = a + 1; i < n; i++) {
		for (int j = 0; j < m; j++) v[i].push_back('N');
	}

	for (int j = 0; j < m; j++) {
		if (j <= b) v[a].push_back('E');
		else v[a].push_back('W');
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << v[i][j];
		cout << '\n';
	}

}