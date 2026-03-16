#include <iostream>
#include <sstream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
10703번. 유성

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		string str; cin >> str;

		if (str.size() == 7) {
			char temp = str[0];
			char temp_2 = str[2];
			if (temp != temp_2) {
				if (temp == str[1] && str[4] == temp) {
					if (temp_2 == str[3] && temp_2 == str[5] && temp_2 == str[6]) cout << "1\n";
					else cout << "0\n";
				}
				else cout << "0\n";
			}

			else cout << "0\n";
		}

		else cout << "0\n";
	}
}