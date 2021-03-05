#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 20001

using namespace std;

vector<int> graph[20001];
int dist[20001];
int maxi = 0;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int idx = pq.top().second; // 현재 인덱스
        int d = -pq.top().first; // 현재까지 거리
        pq.pop();

        if(dist[idx] < d) continue;
        
        for (int i=0; i<graph[idx].size();i++) {
            int next = graph[idx][i];
            int cost = d + 1;

            if (dist[next] > cost){
                dist[next] = cost;
                pq.push({ -cost, next });
                
                if(maxi < cost) maxi = cost;
            }
            
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (vector<int> v : edge) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dijkstra();

    for (int i = 2; i <= n; i++) {
        if (maxi == dist[i]) answer++;
    }

    return answer;
}
