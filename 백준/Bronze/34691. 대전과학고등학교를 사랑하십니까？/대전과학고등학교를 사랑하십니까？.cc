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
	
	while (true) {
		string str; cin >> str;
		if (str.compare("end") == 0) break;

		if (str.compare("animal") == 0) cout << "Panthera tigris\n";
		if (str.compare("flower") == 0) cout << "Forsythia koreana\n";
		if (str.compare("tree") == 0) cout << "Pinus densiflora\n";
	}

}