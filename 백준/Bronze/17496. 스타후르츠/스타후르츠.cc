#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t, c, p;
	cin >> n >> t >> c >> p;

	int time = n / t;
	if (n % t == 0) time -= 1;
	cout << time * c * p;

}