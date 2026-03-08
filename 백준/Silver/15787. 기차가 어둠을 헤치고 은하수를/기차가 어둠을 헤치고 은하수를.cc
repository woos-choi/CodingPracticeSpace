#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 15787번 기차가 어둠을 해치고..
* 구현문제
* set, map은 vector를 key의 자료구조 형으로 가질 수 있다!
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	int n, m; cin >> n >> m;

	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> temp(20, 0);
		v.push_back(temp);
	}

	set<vector<int>> s;
	for (int i = 0; i < m; i++) {
		int type; cin >> type;

		int index, seat;
		if (type == 1 || type == 2) {
			cin >> index >> seat;
			if(type == 1) v[index - 1][seat - 1] = 1;
			if (type == 2) v[index - 1][seat - 1] = 0;
		}

		else if (type == 3 || type == 4) {
			cin >> index;
			if (type == 3) {
				for (int j = v[index - 1].size() - 1; j > 0; j--) {
					v[index - 1][j] = v[index - 1][j - 1];
				}
				v[index - 1][0] = 0;
			}

			if (type == 4) {
				for (int j = 0; j < v[index - 1].size() - 1; j++) {
					v[index - 1][j] = v[index - 1][j + 1];
				}
				v[index - 1][19] = 0;
			}
		}
	}

	//for (int i = 0; i < v.size(); i++) {
	//	for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
	//	cout << '\n';
	//}

	for (int i = 0; i < v.size(); i++) {
		s.insert(v[i]);
	}
	cout << s.size();
}