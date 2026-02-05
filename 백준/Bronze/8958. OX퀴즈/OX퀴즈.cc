#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;


	while (n--) {
		string str; cin >> str;

		int result = 0;
		int flag = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'O') {
				flag++;
				result += flag;
			}

			else flag = 0;
		}

		cout << result << '\n';
	}
}