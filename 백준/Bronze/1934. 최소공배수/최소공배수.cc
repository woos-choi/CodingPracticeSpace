#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int divide(int a, int b) {
	if (a % b == 0) return b;
	else return divide(b, a % b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cout <<  a * b / divide(a, b) << '\n';
	}
}