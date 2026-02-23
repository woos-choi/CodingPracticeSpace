#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int result = 50001;

	int cnt = 0;
	while (true) {
		if (cnt == 0) {
			if (n % 2 == 0) result = min(result, n / 2);
		}

		else {
			if (n >= cnt * 5) {
				if ((n - cnt * 5) % 2 == 0) result = min(result, cnt + (n - cnt * 5) / 2);
			}

			else break;
		}

		cnt++;
	}
	
	if (result != 50001) cout << result;
	else cout << -1;
}