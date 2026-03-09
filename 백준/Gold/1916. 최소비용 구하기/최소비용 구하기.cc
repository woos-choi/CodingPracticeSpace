#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
*1916. 최소비용 구하기
* 그래프 순회를 하면서 최소 거리를 구하는 다익스트라, 벨만포드, 플로이드 워셜 알고리즘 기반의 문제
* 일단은 다익스트라 기반으로 구현 예정( 간선의 비용이 음수인 경우를 제외하고 공부 하겠다는 뜻)
* 우선순위 큐와 배열 하나를 이용해서 최소 거리를 구할 수 있다.
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int start, end, edge;
		cin >> start >> end >> edge;

		v[start].push_back({ edge,end });
		//v[end].push_back({ edge,start });
	}

	//최소 heap을 구성하기 위함
	//pair로 최소 heap을 구성할 때 중요한 것은 first를 edge로 두는 것
	//pair는 내부적으로 우선순위를 정할 때 1순위가 first 이기 때문
	//새로운 자료구조를 생성해 낼 것이 아니면 first를 edge로, second를 vertex로 하는게 맞음
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, INT_MAX);

	int start, end; cin >> start >> end;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();

		if (node.first > dist[node.second]) continue;

		for (int i = 0; i < v[node.second].size(); i++) {
			int temp = node.first + v[node.second][i].first;
			if (dist[v[node.second][i].second] > temp) {
				dist[v[node.second][i].second] = temp;
				pq.push({ temp,v[node.second][i].second });
			}
		}
	}
	
	cout << dist[end];
}