#include<vector>
#include<queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0) continue;
            if(visited[nx][ny] == -1){
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push({nx, ny});
            }
            if(nx == n - 1 && ny == m -1) return visited[nx][ny];
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}
