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
	
	string str;
	string temp;
	getline(cin, str);

	int flag = 0;
	for (int i = 0; i < str.length() - 1; i++) {
		if (str.substr(i, 2) == "D2" || str.substr(i, 2) == "d2") {
			temp = str.substr(i, 2);
			flag = 1;
			break;
		}
	}

	if (flag == 0) cout << "unrated";
	else cout << "D2";

}

