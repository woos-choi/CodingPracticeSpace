#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


/*
* 25425. 운동회
* N팀이 m명의 인원으로 구성
* 라운드당 한명 탈락, 팀의 모든 인원 탈락 시 팀 탈락
* 자신의 팀이 가질 수 있는 범위를 계산해라
* 팀이 가질 수 있는 등수는 남아있는 팀의 수 + 1
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	int a, k; cin >> a >> k;

	int min, max;
	min = n - ((n * m) - a) / m;
	if (a < (n - k)) max = (a - k) + 1;
	else max = n;

	cout << max << " " << min;


}