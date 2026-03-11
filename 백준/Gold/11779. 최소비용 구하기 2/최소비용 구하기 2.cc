#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> v(n + 1);
    for (int i=0; i<m; i++) {
        int start, end, edge;
        cin >> start >> end >> edge;
        v[start].push_back({edge, end});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1,-1);

    int start, end; cin >> start >> end;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        //cout <<"start\n";
        pair<int,int> node = pq.top();
        pq.pop();

        if (node.first > dist[node.second]) continue;
        for (int i=0; i<v[node.second].size(); i++) {
            //누적 거리 계산
            int temp = node.first + v[node.second][i].first;

            if (dist[v[node.second][i].second] > temp) {
                parent[v[node.second][i].second] = node.second;
                dist[v[node.second][i].second] = temp;
                pq.push({temp,v[node.second][i].second});
            }
        }
    }

    //for (int i=1; i<parent.size(); i++) cout << parent[i] << " ";
    //cout << '\n';

    vector<int> path;
    int temp = end;
    path.push_back(end);
    while (true) {
        if (temp == start) break;

        temp = parent[temp];
        path.push_back(temp);
    }

    cout << dist[end] << '\n';
    cout << path.size() << '\n';
    for (int i=path.size() - 1; i>=0; i--) cout << path[i] << ' ';


}



