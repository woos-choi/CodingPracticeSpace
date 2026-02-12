#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed;
	cout.precision(2);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double price;
		char color, coupon, pay;

		cin >> price >> color >> coupon >> pay;
		//cout << price << " " << color << " " << coupon << " " << pay << '\n';

		double temp = price;
		if (color == 'R') temp *= 0.55;
		else if (color == 'G') temp *= 0.7;
		else if (color == 'B') temp *= 0.8;
		else if (color == 'Y') temp *= 0.85;
		else if (color == 'O') temp *= 0.9;
		else if (color == 'W') temp *= 0.95;

		if (coupon == 'C') temp *= 0.95;
		if (pay == 'C') {
			if ((int)(temp * 100) / 10 <= 5) {
				temp = floor(temp * 10) / 10;
			}
			else temp = round(10 * temp) / 10;
		}

		else temp = round(100 * temp) / 100;

		cout << "$" << temp << '\n';
	}
	
}