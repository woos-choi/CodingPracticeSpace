#include <iostream>
#include <vector>
#include <algorithm>

/*
* 1149. RGB 거리
* DP를 사용해야 하는 문제
* 1. 1번 집의 색과 2번 집의 색은 달라야 한다
* 2. N번 집의 색은 N-1번 집의 색과 같지 않아야 한다
* 3. i번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
* 
* --------------------------------------------------------------
* 힌트 얻어낸 포인트
* dp를 단일 배열로 선언하지 말고 색 별로 다 선언해서 계속 이어나간다..
* 왜 배열을 이차원 배열로 선언해서 다 체크하고 넘어가는건 생각을 못했을까..
*/

using namespace std;

class House {
public:
	int red, green, blue;
	int index;

	House(int red, int green, int blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
};

int dp[1000][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<House> v;

	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back(House(a, b, c));
	}

	//이제 벡터를 순회하면서 집을 칠하는 최소 비용을 찾아야 함
	//bottom-up 방식으로 구성하려고 하면 점화식을 잘 찾아야 하고, 초기화가 아주 중요함
	
	dp[0][0] = v[0].red, dp[0][1] = v[0].green, dp[0][2] = v[0].blue;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + v[i].red;
			else if (j == 1) dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + v[i].green;
			else if (j == 2) dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + v[i].blue;
		}
	}

	vector<int> result;
	for (int i = 0; i < 3; i++) result.push_back(dp[n - 1][i]);
	sort(result.begin(), result.end());
	cout << result.front();
}