#include <string>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class line {
public:
	int start;
	int end;
	int cnt;

	line(int start, int end) {
		this->start = start;
		this->end = end;
		cnt = 0;
	}
};

bool find_31(int n) {
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		string temp1 = "No", temp2 = "No";
		if (x <= 23 && x >= 0) {
			if (y <= 59 && y >= 0) temp1 = "Yes";
		}

		if (x > 0 && x <= 12) {
			if (find_31(x)) {
				if (y > 0 && y <= 31) temp2 = "Yes";		}

			else {
				if (x == 2) {
					if (y > 0 && y <= 29) temp2 = "Yes";
				}
				else {
					if (y > 0 && y <= 30) temp2 = "Yes";
				}
			}
		}

		cout << temp1 << " " << temp2 << '\n';
	}
}