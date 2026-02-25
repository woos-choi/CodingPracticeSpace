#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cin.ignore(); //다음이 getline() 이라서 enter를 문자열로 인식하는걸 막기 위함
    map<char, string> m;

    while (n--) {
        string str;
        string print_result = "";
        getline(cin,str);

        //1. 하나의 옵션에 대해 왼쪽에서부터 오른쪽 순서로 단어의 첫 글자가 이미 단축키로 지정되었는지 살펴보기
        istringstream iss(str);
        string buffer;

        int flag = 0;
        while (getline(iss,buffer, ' ')) {
            if (m.find(tolower(buffer[0])) == m.end() && flag == 0) {
                m.insert({tolower(buffer[0]),buffer});
                print_result.append("[");
                print_result.append(buffer.substr(0,1));
                print_result.append("]");
                print_result.append(buffer.substr(1,buffer.size() - 1));
                print_result.append(" ");
                flag = 1;
            }

            else print_result.append(buffer), print_result.append(" ");
        }

        //2. 만약 첫 글자가 이미 다 단축키로 지정이 되어있으면 왼쪽부터 차례대로 알파벳을 보면서 단축키 지정
        if (flag == 0) {
            print_result.clear();
            for (int i=0; i<str.length(); i++) {
                if (str[i] != ' ') {
                    if (m.find(tolower(str[i])) == m.end()) {
                        m.insert({tolower(str[i]),str.substr(i,1)});
                        print_result.append(str.substr(0,i));
                        print_result.append("[");
                        print_result.append(str.substr(i,1));
                        print_result.append("]");
                        print_result.append(str.substr(i + 1,str.length() - i));
                        print_result.append(" ");
                        flag = 2;
                        break;
                    }
                }
            }

            if (flag == 0) print_result = str;

        }

        cout << print_result << '\n';
    }
}