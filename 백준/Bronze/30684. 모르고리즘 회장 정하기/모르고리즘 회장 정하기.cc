#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n; cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		if (temp.length() == 3) v.push_back(temp);
	}

	sort(v.begin(), v.end());
	cout << v.front();
	
}