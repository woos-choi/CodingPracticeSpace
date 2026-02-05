#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
* 2110번 공유기 문제
* 
*/

class Password {
public:
	int num;
	int lower;
	int upper;
	int etc;

	Password() {
		num = 0;
		lower = 0;
		upper = 0;
		etc = 0;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int n; cin >> n;
	string str; cin >> str;
	Password p;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') p.num++;
		else if (str[i] >= 'a' && str[i] <= 'z') p.lower++;
		else if (str[i] >= 'A' && str[i] <= 'Z') p.upper++;
		else p.etc++;
	}

	int result = 0;
	if (p.num == 0) result++;
	if (p.lower == 0) result++;
	if (p.upper == 0) result++;
	if (p.etc == 0) result++;

	if (str.length() + result < 6) result += 6 - (str.length() + result);
	cout << result;
}