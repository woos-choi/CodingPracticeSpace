#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(8);
	for (int i = 0; i < 8; i++) cin >> v[i];

	vector<int> asc(8);
	vector<int> desc(8);
	desc = v;
	asc = v;

	sort(asc.begin(), asc.end());
	//for (int i = 0; i < 8; i++) cout << asc[i];

	sort(desc.begin(), desc.end(), compare);
	
	if (v == asc) cout << "ascending";
	else if (v == desc) cout << "descending";
	else cout << "mixed";
	
	
}