#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
* --------- 고민 과정 ---------
* 처음에는 증가하는 부분 수열의 느낌으로 가려고 했음
* 그런데 이 문제는 연속성을 요구한다는 것이 문제..
* 
* 그냥 브루트포스로 풀었더니 풀리네?
* 그러면 n이 증가하면 어떻게 풀어야 해? -> DP를 떠올리긴 했는데 내가 DP를 잘 모름
* 교안에서는 그리디를 사용함
* 과거의 누적된 값 * 현재값이 현재값보다 크면 현재값을 곱해서 갱신
* 과거의 누적된 값 * 현재값이 현재값보다 작으면 값을 현재값으로 갱신
* O(n)의 그리디 알고리즘
* 
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(3);


	int n; cin >> n;

	vector<double> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	double result = 0;
	double temp;
	for (int i = 0; i < n; i++) {
		if (i == 0) temp = v[i];
		else {
			if (v[i] > temp * v[i]) temp = v[i];
			else temp *= v[i];
		}
		result = max(result, temp);
	}
	cout << result;
}