#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 1504. 특정한 최단 경로
 * 무방향 그래프가 주어짐, 1에서 N으로 최단 거리로 이동
 * 임의로 주어진 두 정점은 반드시 통과하여라
 * 한번 이동했던 정점이나 간선으로 다시 이동할 수 있음
 * -> 두 정점을 반드시 지나면서 최단거리로 목적지까지 이동해라
 */

void dijkstra(vector<vector<pair<int,int>>> &v, vector<int> &dist, int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0,start);

    while (!pq.empty()) {
        pair<int,int> node = pq.top();
        pq.pop();

        for (int i=0; i<v[node.second].size(); i++) {
            int temp = node.first + v[node.second][i].first;
            if (dist[v[node.second][i].second] > temp) {
                dist[v[node.second][i].second] = temp;
                pq.emplace(temp, v[node.second][i].second);
            }
        }
    }
}

void print(vector<int> &dist) {
    for (int i=1; i<=dist.size(); i++) cout << dist[i] << " ";
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, e; cin >> n >> e;

    vector<vector<pair<int,int>>> v(n+1);

    for (int i=0; i<e; i++) {
        int start, end, edge;
        cin >> start >> end >> edge;

        v[start].push_back({edge,end});
        v[end].push_back({edge,start});
    }

    int temp1, temp2; cin >> temp1 >> temp2;

    vector<int> dist(n + 1, INT_MAX);
    vector<int> dist_first(n + 1, INT_MAX);
    vector<int> dist_second(n + 1, INT_MAX);
    vector<int> dist_middle(n + 1,INT_MAX);

    dijkstra(v,dist,1);
    //print(dist);
    dijkstra(v,dist_middle,temp1);
    //print(dist_middle);
    dijkstra(v,dist_first,temp1);
    //print(dist_first);
    dijkstra(v,dist_second,temp2);

    //출발지 -> temp1 -> temp2 -> n
    int result1 = INT_MAX;
    if (dist[temp1] == INT_MAX || dist_middle[temp2] == INT_MAX || dist_second[n] == INT_MAX) {
        result1 = INT_MAX;
    }
    else result1 = dist[temp1] + dist_middle[temp2] + dist_second[n];

    //출발지 -> temp2 -> temp1 -> n
    int result2 = INT_MAX;
    if (dist[temp2] == INT_MAX || dist_middle[temp2] == INT_MAX || dist_first[n] == INT_MAX) {
        result2 = INT_MAX;
    }
    else result2 = dist[temp2] + dist_middle[temp2] + dist_first[n];

    if (result1 == INT_MAX && result2 == INT_MAX) cout << -1;
    else if (result1 == INT_MAX) cout << result2;
    else if (result2 == INT_MAX) cout << result1;
    else {
        if (result1 < result2) cout << result1;
        else cout << result2;
    }

}