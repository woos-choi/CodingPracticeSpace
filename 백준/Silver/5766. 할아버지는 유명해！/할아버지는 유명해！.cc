#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

/*
 * 5766. 할아버지는 유명해!
 */

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.second > b.second) return true;
    if (a.second < b.second) return false;
    if (a.second == b.second) {
        if (a.first < b.first) return true;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<pair<int,int>> v;
        for (int i=0; i<10001; i++) {
            v.push_back({i, 0});
        }

        for (int i=0; i<n *m; i++) {
            int data; cin >> data;
            v[data].second++;
        }

        sort(v.begin(),v.end(),compare);

        int temp = v[1].second;
        for (int i =1; i<=10000; i++) {
            if (v[i].second == temp) cout << v[i].first << " ";
            else break;
        }
        cout << '\n';
    }

}