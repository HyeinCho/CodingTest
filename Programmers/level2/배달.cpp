#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[51];
vector<pair<int, int>> graph[51];

void dijkstra(int N){
    for(int i=1;i<=N;i++) dist[i] = 500000;
    queue<pair<int, int>> q;
    q.push({0, 1});
    dist[1] = 0;
    
    while(!q.empty()){
        int cost = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(dist[x] < cost) continue;
        
        for(int i=0;i<graph[x].size();i++){
            int nx = graph[x][i].first;
            int ncost = graph[x][i].second + cost;
            
            if(dist[nx] < ncost) continue;
            dist[nx] = ncost;
            q.push({ncost, nx});
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=0;i<road.size();i++){
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    dijkstra(N);
    
    for(int i=1;i<=N;i++) {
        if(dist[i] <= K) answer++;
    }
    
    return answer;
}
