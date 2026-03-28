#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int INF = 1000000000;

void print(vector<vector<int>> &v) {
    for (int i =1;i < v.size(); i++) {
        for (int j=1; j<v[i].size(); j++) {
            if (v[i][j] != INF) cout << v[i][j] << " ";
            else cout << "0 ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> v;
    for (int i=0; i<=n; i++) {
        vector<int> temp(n + 1);
        v.push_back(temp);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) v[i][j] = 0;
            else v[i][j] = INF;
        }
    }

    for (int i=0; i<m; i++) {
        int start, end ,edge;
        cin >> start >> end >> edge;

        v[start][end] = min(v[start][end],edge);
    }

    //print(v);

    //k 노드를 끼워서 가는 경우
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<=n; j++) {
                if (!((i == j) || (i == k) || (j == k))) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
    }

    print(v);
}