#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 1753번. 최단경로
* 방향그래프가 주어졌을 때 다른 모든 정점으로의 최단 경로를 구하여라 -> 다익스트라 쓰라는 것
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	int start_v; cin >> start_v;

	vector<vector<pair<int, int>>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int start, end, edge;
		cin >> start >> end >> edge;

		v[start].push_back({ edge,end });
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, INT_MAX);

	pq.push({ 0,start_v });
	dist[start_v] = 0;


	//pair가 {간선, 정점}의 형태임을 잊지 말 것
	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();

		if (node.first > dist[node.second]) continue;

		for (int i = 0; i < v[node.second].size(); i++) {
			int temp = node.first + v[node.second][i].first;
			if (dist[v[node.second][i].second] > temp) {
				dist[v[node.second][i].second] = temp;
				pq.push({ temp, v[node.second][i].second });
			}
		}
	}

	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == INT_MAX) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

}