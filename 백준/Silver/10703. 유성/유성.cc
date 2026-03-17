#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void print(vector<vector<char>> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) cout << v[i][j];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, s; cin >> r >> s;
    vector<vector<char>> v(r);
    vector<vector<int>> meteor(s);

    for (int i=0; i<r; i++) {
        for (int j=0; j<s; j++) {
            char data; cin >> data;
            if (data == '.' || data == 'X') {
                v[i].push_back('.');
                if (data == 'X') meteor[j].push_back(i);
            }

            else if (data == '#') v[i].push_back('#');
        }
    }

    int flag = 0;
    while (true) {
        //cout << "loop\n";
        for (int j=0; j<s; j++) {
            if (meteor[j].size() > 0 && meteor[j].back() + 1 < r) {
                if (v[meteor[j].back() + 1][j] == '#') {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) break;
        for (int j=0; j<s; j++) {
            if (meteor[j].size() > 0) {
                for (int i=meteor[j].size(); i>=0; i--) meteor[j][i] += 1;

            }
        }
    }

    for (int j=0; j<s; j++) {
        for (int i=0; i<meteor[j].size(); i++) v[meteor[j][i]][j] = 'X';
    }

    print(v);
}