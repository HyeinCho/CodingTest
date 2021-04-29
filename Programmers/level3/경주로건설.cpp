#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int dist[25][25][4];

int dijkstra(vector<vector<int>> board) {
    int n = board.size();
    int MAX = n * n * 500 + 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) dist[i][j][k] = MAX;
        }
    }
    for (int k = 0; k < 4; k++) dist[0][0][k] = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // 거리, 방향, x, y
    pq.push({ 0, 0, 0, 0 });
    pq.push({ 0, 1, 0, 0 });
    pq.push({ 0, 2, 0, 0 });
    pq.push({ 0, 3, 0, 0 });

    while (!pq.empty())
    {
        vector<int> tmp = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tmp[2] + dx[i];
            int ny = tmp[3] + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 1) continue;

            if (abs(i-tmp[1]) == 2) continue;
            
            int ncost = dist[tmp[2]][tmp[3]][tmp[1]] + 100;
            if (i != tmp[1]) ncost += 500;
            
            if (dist[nx][ny][i] > ncost) {
                pq.push({ ncost,i,nx,ny });
                dist[nx][ny][i] = ncost;
            }
        }
    }

    int result = MAX;
    for (int i = 0; i < 4; i++) {
        if (result > dist[n - 1][n - 1][i]) result = dist[n - 1][n - 1][i];
    }
    return result;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = dijkstra(board);
    return answer;
}
