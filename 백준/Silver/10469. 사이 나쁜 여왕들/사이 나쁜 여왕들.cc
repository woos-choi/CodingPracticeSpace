#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check(char arr[8][8],pair<int,int> data);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char arr[8][8];
    vector<pair<int,int>> v;

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') v.emplace_back(i,j);
        }
    }
    
    if (v.size() != 8) {
        cout << "invalid";
        return 0;
    }

    //for (int i=0; i<8; i++) {
    //    for (int j=0; j<8; j++) cout << arr[i][j] << " ";
    //    cout << '\n';
    //}

    //for (int i=0; i<8; i++) cout << v[i].first << " " << v[i].second << '\n';

    int flag = 0;
    for (int i=0; i<v.size(); i++) {
        for (int j= i + 1; j<v.size(); j++) {
            if (v[i].first == v[j].first || v[i].second == v[j].second) {
                //cout << "수직 관계 불일치\n";
                flag = 1;
                break;
            }

            if (abs(v[i].first - v[j].first) == abs(v[i].second - v[j].second)) {
                //cout << "대각선 관계 불일치\n";
                flag = 1;
                break;
            }
        }

        if (flag == 1) break;
    }

    if (flag == 0) cout << "valid";
    else cout << "invalid";
}



