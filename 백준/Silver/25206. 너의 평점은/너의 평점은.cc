#include <iostream>
#include <sstream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double sum = 0;
	double size = 0;
	for (int i = 0; i < 20; i++) {
		string str;
		double temp;
		string buffer;
		cin >> str >> temp >> buffer;
		size += temp;

		if (buffer.compare("A+") == 0) sum += temp * 4.5;
		if (buffer.compare("A0") == 0) sum += temp * 4.0;
		if (buffer.compare("B+") == 0) sum += temp * 3.5;
		if (buffer.compare("B0") == 0) sum += temp * 3.0;
		if (buffer.compare("C+") == 0) sum += temp * 2.5;
		if (buffer.compare("C0") == 0) sum += temp * 2.0;
		if (buffer.compare("D+") == 0) sum += temp * 1.5;
		if (buffer.compare("D0") == 0) sum += temp;
		if (buffer.compare("P") == 0) size -= temp;
	}

	cout << fixed;
	cout.precision(10);
	sum /= size;
	cout << sum;

}