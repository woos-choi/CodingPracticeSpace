#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str; cin >> str;
	int len = str.length() / 2;
	string sub_str = str.substr(0, len);
	string sub_str_2 = str.substr(len, len);
	
	int n1 = stoi(sub_str);
	int n2 = stoi(sub_str_2);


	int temp1 = 0, temp2 = 0;

	while (n1 > 0) {
		temp1 += n1 % 10;
		n1 /= 10;
	}

	while (n2 > 0) {
		temp2 += n2 % 10;
		n2 /= 10;
	}

	if (temp1 == temp2) cout << "LUCKY";
	else cout << "READY";

}