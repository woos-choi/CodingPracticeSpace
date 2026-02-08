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
* 숫자가 연속적으로 곱해졌을 때 1보다 작은 숫자가 곱해지면 작아짐..
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
	for (int i = 0; i < n; i++) {
		double temp = v[i];
		result = max(result, v[i]);
		for (int j = i + 1; j < n; j++) {
			result = max(result, temp * v[j]);
			//cout << temp * v[j] << " ";
			temp *= v[j];
		}
		//cout << '\n';
	}
	cout << result;
}