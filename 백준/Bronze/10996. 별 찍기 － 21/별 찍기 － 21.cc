#include <string>
#include <memory.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	string first = "";
	string second = "";

	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) first.append("* ");
		for (int i = 0; i < n / 2; i++) second.append(" *");
	}

	else {
		for (int i = 0; i < n / 2 + 1; i++) first.append("* ");
		for (int i = 0; i < n / 2; i++) second.append(" *");
	}


	if (n == 1) cout << first;
	else {
		for (int i = 0; i < n; i++) {
			cout << first << '\n';
			cout << second << '\n';
		}
	}
}