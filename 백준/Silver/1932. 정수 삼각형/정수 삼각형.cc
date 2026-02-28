#include <string>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/*
* DP - 큰 문제를 작은 문제로 쪼개서 푸는 기법
* 이미 푼놈은 안 풀고 꽁쳐뒀다가 나중에 날먹하는 기법
* 최적해 구하는 문제( 최대, 최소, 최적의 값)
* 똑같은 거가 반복되는 문제 -> 이걸 재귀로 풀면 시간초과 나는 문제
* Top - Down 방식, Bottom - Up 방식
* 
*/

vector<vector<int>> v;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n; cin >> n;
	int result;

	vector<vector<int>> dp(n);

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j <= i; j++) {
			int data; cin >> data;
			temp.push_back(data);
		}
		v.push_back(temp);

		dp[i] = vector<int>(i + 1);
	}

	dp[0][0] = v[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) dp[i][j] = dp[i - 1][0] + v[i][j];

			else if (j == v[i].size() - 1) dp[i][j] = dp[i - 1][v[i - 1].size() - 1] + v[i][j];

			//자신 INDEX와 전 INDEX
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
			}
		}
	}

	/*for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) cout << dp[i][j] << " ";
		cout << '\n';
	}*/

	for (int i = 0; i < dp[dp.size() - 1].size(); i++) {
		result = max(result, dp[dp.size() - 1][i]);
	}

	cout << result;
	
}

