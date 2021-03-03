#include <iostream>
#include <vector>
#include <queue>

#define INF 100000001

using namespace std;

int dist[1001]; // 최단 거리 테이블
vector<pair<int, int>> vec[1001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열

void dijkstra(int start) {
	dist[start] = 0; // 처음 위치는 0

	priority_queue<pair<int, int>> pq; // 거리, 인덱스
	pq.push({ 0 , start });

	while (!pq.empty()) {
		int cur = pq.top().second; // 현재 노드
		int distance = pq.top().first * -1; // 현재 노드까지의 비용
		pq.pop();

		if (dist[cur] < distance) continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // 다음 노드
			int nextDistance = distance + vec[cur][i].second; // 다음 노드까지 비용

			// 다음 것과 기존의 비용과 비교
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance * -1 , next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int start, end;
	int N, M;
	cin >> N; // 정점 갯수
	cin >> M; // 간선 갯수

	for (int i = 1; i <= N; i++) dist[i] = INF;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}

	cin >> start >> end;

	dijkstra(start);

	cout << dist[end];

	return 0;
}

// 시간 초과 (플로이드와샬)
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> m;
//	vector<vector<int>> v(n + 1, vector<int>(n + 1, INF));
//	for (int i = 0; i < m; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (v[a][b] > c) {
//			v[a][b] = c;
//		}
//		
//	}
//
//	for (int i = 1; i <= n; i++) v[i][i] = 0;
//
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (v[i][j] > v[i][k] + v[k][j]) {
//					v[i][j] = v[i][k] + v[k][j];
//				}
//			}
//		}
//	}
//
//	int s, e;
//	cin >> s >> e;
//	cout << v[s][e];
//
//	return 0;
//}
