#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
int max_result = -987654321;
vector<int> num;
vector<char> oper;

int cal(char op, int a, int b) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return a / b;
}

void go(int index, int cnt) {

    //cout << index << " : " << cnt << '\n';

    if (index == num.size() - 1) {
        max_result = max(max_result, cnt);
        return;
    }

    //ex) 3 * 8 + 5
    //1. 3개의 index와 2개의 oper가 있다고 가정했을때, 앞 2개를 먼저하는 경우 -> 이 경우는 만약, 내가 마지막 index라면 return 하고 끝나니까 if문 필요없음
    go(index + 1, cal(oper[index], cnt, num[index + 1]));

    //뒤 2개를 먼저하는 경우 -> 뒤 2개가 있어야만 연산이 가능 (오버플로우 체크                
    if (index + 2 <= num.size() - 1) {
        int temp = cal(oper[index + 1], num[index + 1], num[index + 2]);
        go(index + 2, cal(oper[index], cnt, temp));
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    string str; cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') num.push_back(stoi(str.substr(i, 1)));
        else oper.push_back(str[i]);
    }
    
    /*for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
    cout << '\n';
    for (int i = 0; i < oper.size(); i++) cout << oper[i] << " ";*/

    go(0, num[0]);
    cout << max_result;
}


