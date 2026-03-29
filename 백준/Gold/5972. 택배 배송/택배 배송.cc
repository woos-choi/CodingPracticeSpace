#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

/*
* 5972. 택배 배송
* 그냥 다익스트라로 풀 수 있을 것 같음
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> v(n + 1);

    for (int i=0; i<m; i++) {
        int start ,end, edge;
        cin >> start >> end >> edge;

        v[start].emplace_back(edge,end);
        v[end].emplace_back(edge,start);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> dist (n + 1, INT_MAX);

    dist[1] = 0;
    pq.push({0,1});

    while (!pq.empty()) {
        pair<int,int> node = pq.top();
        pq.pop();

        for (int i=0; i<v[node.second].size(); i++) {
            int temp = v[node.second][i].first + node.first;
            if (dist[v[node.second][i].second] > temp) {
                dist[v[node.second][i].second] = temp;
                pq.push({temp, v[node.second][i].second});
            }
        }
    }

    cout << dist[n];

}