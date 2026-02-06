#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
* 2110번 공유기 문제
* 내가 본 힌트 - 왜 첫번째에 공유기를 무조건 박아도 되는가 -> 인접한 공유기의 최대거리이기 때문
*/

void print_vector(vector<vector<int>>& v, int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cout << v[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w; cin >> h >> w;
	vector<vector<int>> v(h, vector<int>(w, 0));
	int result = 0;
	
	for (int i = 0; i < w; i++) {
		int temp; cin >> temp;

		for (int j = 0; j < temp; j++) {
			v[h - j - 1][i] = 1;
		}
	}

	//print_vector(v, h, w);

	//cout <<" i " << i << " j " << j  << " 빗물이 저장 : " << j - flag - 1 << '\n';
	//1이 연속으로 나오는 경우는 걸러줘야함
	for (int i = 0; i < h; i++) {
		int flag = -1, cnt = 0;

		for (int j = 0; j < w; j++) {
			if (v[i][j] == 1) {
				if (cnt == 0) flag = i;
				else {
					//cout << " i " << i << " j " << j << " 빗물이 저장 : " << cnt << '\n';
					result += cnt;
					cnt = 0;
					flag = i;
				}
			}

			else {
				if (flag != -1) cnt++;
			}
		}
	}

	cout << result;
}