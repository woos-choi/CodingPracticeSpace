#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>


using namespace std;

class Data {
public:
	int num;
	string str;

	Data(int num) {
		this->num = num;
		str = "";
	}
	
	stack<string> s;
	void make_str() {

		int temp = num;
		while (temp > 0) {
			if (temp % 10 == 0) s.push("zero");
			else if (temp % 10 == 1) s.push("one");
			else if (temp % 10 == 2) s.push("two");
			else if (temp % 10 == 3) s.push("three");
			else if (temp % 10 == 4) s.push("four");
			else if (temp % 10 == 5) s.push("five");
			else if (temp % 10 == 6) s.push("six");
			else if (temp % 10 == 7) s.push("seven");
			else if (temp % 10 == 8) s.push("eight");
			else s.push("nine");

			temp /= 10;
		}

		while (!s.empty()) {
			str.append(s.top());
			s.pop();

			if (!s.empty()) str.append(" ");
		}
	}
};

bool compare(Data a, Data b) {
	if (a.str < b.str) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	
	vector<Data> v;
	for (int i = n; i <= m; i++) {
		v.push_back(Data(i));
	}

	for (int i = 0; i < v.size(); i++) {
		v[i].make_str();
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && i % 10 == 0) {
			cout << '\n';
		}

		cout << v[i].num << " ";
	}

}