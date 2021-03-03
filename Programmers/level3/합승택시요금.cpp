#include <string>
#include <vector>
#include <queue>
#define INF 20000001

using namespace std;

// 플로이드 와샬 O(N^3)
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> taxi(n+1, vector<int>(n+1, INF));
    for(vector<int> tmp : fares){
        taxi[tmp[0]][tmp[1]] = tmp[2];
        taxi[tmp[1]][tmp[0]] = tmp[2];
    }
    for(int i=1;i<=n;i++) taxi[i][i] = 0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(taxi[i][j] > taxi[i][k] + taxi[k][j]){
                    taxi[i][j] = taxi[i][k] + taxi[k][j];
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int tmp = taxi[s][i] + taxi[i][a] + taxi[i][b];
        if(answer > tmp) answer = tmp;
    }
    
    return answer;
}

// 다익스트라 O( N * ElogN )
vector<pair<int,int>> graph[201];

vector<int> dijkstra(int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, s});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        
        if(d[cur] < dist) continue;
        
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second + dist;
            
            if(d[next] > cost){
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
    return d;
}

int solution1(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(vector<int> tmp : fares){
        graph[tmp[0]].push_back({tmp[1], tmp[2]});
        graph[tmp[1]].push_back({tmp[0], tmp[2]});
    }
    
    vector<int> ds = dijkstra(n, s);
    vector<int> da = dijkstra(n, a);
    vector<int> db = dijkstra(n, b);
    
    for(int i=1;i<=n;i++){
        int tmp = ds[i] + da[i] + db[i];
        if(answer > tmp) answer = tmp;
    }
    
    return answer;
}
