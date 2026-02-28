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


int dp[301];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n; cin >> n;
	string str = "n";
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	//초기화
	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[0], v[1]) + v[2];

	//점화식을 찾아야 함
	//1. 2칸 전이면 연속된게 아니니까 그냥 비교하면 됨
	//2. 바로 전 칸이면 연속되면 안되니까 3번째 칸 전거에다가 전칸이 필수적
	//3. 그리고 현재칸 더하기
	for (int i = 3; i < v.size(); i++) {
		dp[i] = max(v[i - 1] + dp[i - 3], dp[i - 2]) + v[i];
	}

	cout << dp[v.size() - 1];
}

