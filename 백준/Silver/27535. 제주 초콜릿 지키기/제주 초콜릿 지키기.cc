#include <iostream>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

class Data {
public:
    string data;
    int cnt;

    Data(string data, int cnt) {
        this->data = data;
        this->cnt = cnt;
    }
};

bool compare(Data data1, Data data2) {
    if (data1.cnt > data2.cnt) return true;
    else if (data1.cnt < data2.cnt) return false;
    else {
        if (data1.data < data2.data) return true;
        else return false;
    }
}

//10진수 data를 depth진법으로 바꾸기(depth는 2~9진법)
string convert(int data, int depth) {
    string result ="";

    stack<int> s;
    while (true) {
        if (data == 0) break;
        s.push(data % depth);
        data /= depth;
    }

    while (!s.empty()) {
        result += to_string(s.top());
        s.pop();
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> type = {"H","T","C","K","G"};
    vector<Data> v;

    int sum = 0;
    for (int i=0; i<5; i++) {
        int data; cin >> data;
        v.push_back(Data(type[i],data));
        sum += data;
    }

    int n; cin >> n;
    for (int i=0; i<n; i++) {
        vector<int> temp(5);
        for (int j=0; j<5; j++) cin >> temp[j];

        vector<Data> temp_sort = v;
        int temp_sum = 0;
        for (int j=0; j<5; j++) {
            temp_sum += temp[j];
            temp_sort[j].cnt -= temp[j];
        }

        v = temp_sort;
        sort(temp_sort.begin(), temp_sort.end(), compare);
        if (sum % 10 == 0 || sum % 10 == 1) {
            sum -= temp_sum;
            cout << sum << "7H\n";
        }

        else {
            string temp_data;
            if (convert(sum - temp_sum,sum % 10) == "") temp_data = "0";
            else temp_data = convert(sum - temp_sum,sum % 10);
            cout << temp_data << "7H\n";
            sum -= temp_sum;
        }

        if (sum == 0) cout << "NULL\n";
        else {
            for (int j=0; j<5; j++) {
                if (temp_sort[j].cnt > 0) cout << temp_sort[j].data;
            }
            cout << '\n';
        }
    }
}

