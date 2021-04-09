#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> tmp(4, vector<int>(4));
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

pair<int, pair<int, int>> bfs(int r, int c, int num, pair<int,int> destination) {
    //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {r,c}});

    while (!q.empty()) {
        /*int x = q.top().second.first;
        int y = q.top().second.second;
        int d = q.top().first;*/
        int x = q.front().second.first;
        int y = q.front().second.second;
        int d = q.front().first;

        q.pop();
        if (tmp[x][y] == num) {
            if (destination.first == -1 && destination.second == -1) { 
                if (r != x || c != y) {
                    return { d, {x, y}};
                }
            }
            else {
                return { d, {x, y} };
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            q.push({ d + 1, {nx,ny} });
            if (tmp[nx][ny] == 0) {
                int cnt = 0;
                while (1) {
                    if (tmp[nx][ny] != 0) break;
                    else if (nx + dx[i] < 0 || nx + dx[i] >= 4 || ny + dy[i] < 0 || ny + dy[i] >= 4) break;
                    nx += dx[i];
                    ny += dy[i];
                    cnt++;
                }
                if (cnt > 0) q.push({ d + 1, {nx,ny} });
            }

        }
    }

}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 987654321;
    
    vector<pair<int, pair<int,int>>> card;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) card.push_back({board[i][j], { i, j } });
        }
    }
    sort(card.begin(), card.end());

    vector<int> permu(card.size() / 2);
    for (int i = 0; i < permu.size(); i++) permu[i] = i + 1;
    do {
        int result = 0;
        int x = r;
        int y = c;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) tmp[i][j] = board[i][j];
        }

        for (int i = 0; i < permu.size();i++) {
            int num = permu[i];

            //  
            // 해당 넘버의 시작 지점 찾기
            pair<int, pair<int, int>> start1 = bfs(x, y, num, card[2 * (num - 1)].second);

            // 해당 넘버의 끝 지점 찾기
            pair<int, pair<int, int>> end1 = bfs(start1.second.first, start1.second.second, num, { -1,-1 });

            // 반대방향
            // 해당 넘버의 시작 지점 찾기
            pair<int, pair<int, int>> start2 = bfs(x, y, num, card[2 * num - 1].second);

            // 해당 넘버의 끝 지점 찾기
            pair<int, pair<int, int>> end2 = bfs(start2.second.first, start2.second.second, num, { -1,-1 });

            if (start1.first + end1.first > start2.first + end2.first) {
                tmp[start2.second.first][start2.second.second] = 0;
                tmp[end2.second.first][end2.second.second] = 0;
                result += start2.first + end2.first + 2;
                x = end2.second.first;
                y = end2.second.second;
            }
            else {
                tmp[start1.second.first][start1.second.second] = 0;
                tmp[end1.second.first][end1.second.second] = 0;
                result += start1.first + end1.first + 2;
                x = end1.second.first;
                y = end1.second.second;
            }

            if (result > answer) break;
        }
        if (answer > result) answer = result;

    } while (next_permutation(permu.begin(), permu.end()));


    return answer;
}
