#include <string>
#include <memory.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(vector<char>& v) {
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str; cin >> str;
	string bomb; cin >> bomb;
	char bomb_back = bomb.back();

	vector<char> v;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str[i]);
		
		if (str[i] == bomb_back && v.size() >= bomb.length()) {

			int temp_size = 0;
			while (true) {
				if (temp_size >= bomb.length()) {
					v.erase(v.begin() + v.size() - temp_size, v.begin() + v.size());
					break;
				}

				if (v[v.size() - 1 - temp_size] == bomb[bomb.length() - 1 - temp_size]) {
					temp_size++;
				}

				else break;
			}
		}
		//print_vector(v);
	}

	if (v.size() != 0) for (int i = 0; i < v.size(); i++) cout << v[i];
	else cout << "FRULA";

}

