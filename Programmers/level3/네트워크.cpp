#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void bfs(int idx, int n, vector<vector<int>> computers){
    queue<int> q;
    q.push(idx);
    visited[idx] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i=0;i<n;i++){
            if(i == x) continue;
            if(computers[x][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(n);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}
