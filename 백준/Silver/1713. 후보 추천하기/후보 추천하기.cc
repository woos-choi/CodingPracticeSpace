#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 1713. 후보 추천하기
 * 학생 추천 시작 전 모든 사진틀은 공백
 * 특정 학생을 추천하면, 추천 학생 사진이 무조건 반영되어야 함
 * 비어있는 사진틀이 없는 경우, 추천 받은 횟수가 가장 적은 사진 삭제, 2명인 경우는 게시된 지 오래된 걸 삭제
 * 이미 개시된 학생이 추천 받으면 추천 횟수만 올려라
 * 삭제되는 경우에는 해당 학생의 추천 횟수는 0이 된다.
 */

class Data {
public:
    int index;
    int cnt;
    int time;

    Data(int index, int cnt, int time) {
        this->index = index;
        this->cnt = cnt;
        this->time = time;
    }
};

bool compare(Data a, Data b) {
    if (a.cnt < b.cnt) return true;
    if (a.cnt > b.cnt) return false;
    if (a.cnt == b.cnt) {
        if (a.time < b.time) return true;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int t; cin >> t;

    set<int> s;
    vector<Data> v;

    for (int i=0; i<t; i++) {
        int data; cin >> data;
        if (s.find(data) == s.end()) {
            Data temp(data,1,i);
            if (v.size() >= n) {
                sort(v.begin(), v.end(),compare);
                //cout << "vector : ";
                //for (int j=0; j<v.size(); j++) cout << v[j].index << " ";
                //cout << '\n';
                s.erase(v.front().index);
                v[0] = temp;
            }

            else v.push_back(temp);
            s.insert(data);
        }

        else {
            for (int j=0; j<v.size(); j++) {
                if (v[j].index == data) {
                    v[j].cnt++;
                    break;
                }
            }
        }

        //for (auto iter = s.begin(); iter != s.end(); ++iter) cout << *iter << " ";
        //cout << '\n';
    }

    for (auto iter = s.begin(); iter != s.end(); ++iter) cout << *iter << " ";
}