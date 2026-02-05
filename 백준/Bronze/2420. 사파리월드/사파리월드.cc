#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m; cin >> n >> m;
	
	if (n > m) cout << n - m;
	else cout << m - n;
}