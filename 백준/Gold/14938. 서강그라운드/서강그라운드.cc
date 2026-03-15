#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

/**
 * 14938번. 서강그라운드
 * 최단거리 찾기 알고리즘 + 경로 역추적 하기
 * dist를 각 node에서 시작할 때로 바꾸면 좋을 듯
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //n : 지역의 갯수, m : 수색범위, r : 길의 갯수
    int n, m, r; cin >> n >> m >> r;

    vector<pair<int,int>> node_info(n + 1);

    for (int i=0; i<n; i++) {
        int data; cin >> data;
        node_info[i + 1].first = i + 1;
        node_info[i + 1].second = data;
    }

    vector<vector<pair<int,int>>> v(n + 1);
    int max_result = 0;

    //양방향 간선임을 잊지 말 것, 그래프 생성
    for (int i=0; i<r; i++) {
        int start, end, edge;
        cin >> start >> end >> edge;
        v[start].push_back({edge,end});
        v[end].push_back({edge,start});
    }

    for (int i=1; i<=n; i++) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> pos(n + 1, -1);

        pq.push({0,i});
        dist[i] = 0;

        while (!pq.empty()) {
            pair<int,int> node = pq.top();
            pq.pop();

            for (int j=0; j<v[node.second].size(); j++) {
                int temp = node.first + v[node.second][j].first;
                if (dist[v[node.second][j].second] > temp) {
                    dist[v[node.second][j].second] = temp;
                    pq.push({temp,v[node.second][j].second});
                    pos[v[node.second][j].second] = node.second;
                }
            }
        }

        //현재 위치에서 갈 수 있는 곳 체크하고 갈 수 있는 곳만 더해서 max_result 갱신하기
        int temp_sum = 0;
        for (int j=1; j<=n; j++) {
            if (dist[j] <=m ) temp_sum += node_info[j].second;
        }
        max_result = max(max_result,temp_sum);
    }

    cout << max_result;
}




