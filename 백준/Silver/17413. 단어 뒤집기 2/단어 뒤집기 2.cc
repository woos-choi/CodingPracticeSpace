#include <string>
#include <memory.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	getline(cin, str);
	int len = str.length();

	//새로운 단어의 트리거 
	//1. <의 등장 
	//2. 공백의 등장(단, <> 사이에 존재하는 공백은 트리거로 치지 않음)
	//3. >의 등장

	//단어 저장의 트리거
	//1. <의 등장
	//2. >의 등장
	//3. 공백의 등장

	int flag = 0;
	string result = "";
	string temp_tag = "";
	stack<char> s;

	for (int i = 0; i < len; i++) {
		if (str[i] == '<') {
			if (flag == 0) {
				while (!s.empty()) {
					result.push_back(s.top());
					s.pop();
				}
				//cout << "단어 저장 출력 테스트 : " << result << "\n";
			}

			temp_tag.push_back('<');
			flag = 1;
		}

		else if (str[i] == '>') {
			temp_tag.push_back('>');
			result.append(temp_tag);
			//cout << "단어 저장 출력 테스트 : " << result << "\n";
			temp_tag.clear();
			flag = 0;
		}

		else if (str[i] == ' ') {
			if (flag == 1) temp_tag.push_back(str[i]);
			else if (flag == 0) {
				while (!s.empty()) {
					result.push_back(s.top());
					s.pop();
				}
				//cout << "단어 저장 출력 테스트 : " << result << "\n";
				result.push_back(' ');
			}
		}

		else {
			if (flag == 0) s.push(str[i]);
			else temp_tag.push_back(str[i]);
		}
	}

	if (temp_tag != "") result.append(temp_tag);
	if (!s.empty()) {
		while (!s.empty()) {
			result.push_back(s.top());
			s.pop();
		}
	}

	cout << result;
	
}