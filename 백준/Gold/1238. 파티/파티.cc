#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 1238. 파티
 * n명의 학생, m개의 단방향 도로, x의 집에서 파티가 이루어짐
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x; cin >> n >> m >> x;

    vector<int> result(n + 1, 0);
    vector<vector<pair<int,int>>> v(n + 1);

    for (int i=0; i<m; i++) {
        int start, end, edge;
        cin >> start >> end >> edge;

        v[start].push_back({edge,end});
    }

    for (int i=1; i<=n; i++) {
        vector<int> dist_go(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist_go[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {
            pair<int,int> node = pq.top();
            pq.pop();

            for (int j=0; j<v[node.second].size(); j++) {
                if (dist_go[v[node.second][j].second] > node.first + v[node.second][j].first) {
                    dist_go[v[node.second][j].second] = node.first + v[node.second][j].first;
                    pq.push({dist_go[v[node.second][j].second],v[node.second][j].second});
                }
            }
        }

        if (i == x) {
            for (int j=1; j<=n; j++) result[j] += dist_go[j];
        }

        else {
            result[i] += dist_go[x];
        }
    }

    //for (int i=1; i<=n; i++) cout << result[i] << " ";
    int max_result = -1;
    result[x] = 0;
    for (int i=1; i<=n; i++) max_result = max(max_result,result[i]);
    cout << max_result;
}