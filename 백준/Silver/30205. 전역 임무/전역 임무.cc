#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, p;
    cin >> n >> m >> p;

    vector<vector<long long>> v;
    vector<int> item_cnt(n,0);

    for (int i=0; i<n; i++) {
        vector<long long> temp;
        for (int j=0; j<m; j++) {
            long long data; cin >> data;

            if (data == -1) item_cnt[i]++;
            else temp.push_back(data);
        }

        sort(temp.begin(),temp.end());
        v.push_back(temp);
    }

    //for (int i=0; i<n; i++) cout << item_cnt[i] << " ";
    //cout << '\n';

    int flag = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<v[i].size(); j++) {
            //cout << "p : " << p << '\n';
            if (p >= v[i][j]) p += v[i][j];
            else {
                while (item_cnt[i] > 0) {
                    p *= 2;
                    item_cnt[i]--;
                    if (p >= v[i][j]) {
                        p += v[i][j];
                        break;
                    }
                }

                if (p < v[i][j]) {
                    //cout << i << " " << j << " level out\n";
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 0) break;
        for (int j=0; j<item_cnt[i]; j++) p *= 2;
        item_cnt[i] = 0;
    }

    cout << flag;

}