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

	double sum = 0;
	double result;
	vector<double> v;
	for (int i = 0; i < n; i++) {
		double data; cin >> data;
		v.push_back(data);
		result = max(data, result);
	}

	for (int i = 0; i < n; i++) {
		v[i] = v[i] / result * 100;
		sum += v[i];
	}

	sum /= n;

	cout << fixed;
	cout.precision(20);

	
	cout << sum;
}