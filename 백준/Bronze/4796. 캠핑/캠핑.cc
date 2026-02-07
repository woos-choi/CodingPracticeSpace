#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int index = 1;
	while (true) {
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;
		int cnt = 0;
		cnt += (V / P) * L;

		int temp = V - (V / P) * P;
		if (L < temp) cnt += L;
		else cnt += temp;

		cout << "Case " << index++ << ": " << cnt << '\n';
	}
}