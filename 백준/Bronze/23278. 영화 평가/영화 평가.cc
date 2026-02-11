#include <string>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, l, h;
	cin >> n >> l >> h;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	double sum = 0, cnt = n - l - h;
	for (int i = 0 + l; i < n - h; i++) {
		sum += v[i];
	}

	sum /= cnt;
	cout.precision(17);
	cout << sum;
}

