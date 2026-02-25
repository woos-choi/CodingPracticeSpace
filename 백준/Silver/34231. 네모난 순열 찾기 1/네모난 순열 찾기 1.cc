#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Dot {
public:
    int x, y;

    Dot(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

void print_set(set<int> &s) {
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }
}

int main() {
    int n; cin >> n;
    int cnt = 0;

    int arr[n][n];
    vector<Dot> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n; j++) {
            cin >> arr[i][j];
            v.emplace_back(i,j);
        }
    }

    for (int i=0; i<v.size(); i++) {
        for (int j = i; j<v.size(); j++) {
            if (v[i].x <= v[j].x && v[i].y <= v[j].y) {
                set<int> s;

                for (int x = v[i].x; x <= v[j].x; x++) {
                    for (int y = v[i].y; y <= v[j].y; y++) {
                        s.insert(arr[x][y]);
                    }
                }

                if (s.size() == (v[j].y - v[i].y + 1) * (v[j].x - v[i].x + 1)) {
                    int temp_data = 1;
                    int flag = 0;
                    for (auto iter = s.begin(); iter != s.end(); iter++) {
                        if (*iter == temp_data) temp_data++;
                        else {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) cnt++;
                }
            }

            else continue;
        }
    }


    cout << cnt;
}