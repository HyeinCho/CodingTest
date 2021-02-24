/*
플로이드 와샬로 풀어야함
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> v(n + 1, vector<int>(n + 1, false));
    for (vector<int> tmp : results) {
        v[tmp[0]][tmp[1]] = true; // tmp[0]가 tmp[1]을 이긴 경우
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // i가 k를 이기고, k가 j를 이긴 경우 => i가 j를 이긴 경우
                if (v[i][k] && v[k][j]) {
                    v[i][j] = true;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (v[i][j] || v[j][i]) { // i가 j를 이겼거나, j가 i를 이긴 경우 (하나라도 이기면 됨. 즉 승패가 확실한 경우). 만약 둘 다 false라는 것은 누가 이긴지 모른다는 것
                cnt++;
            }
        }
        // 승패가 확실한 경우가 n-1이라는 것은 해당 위치가 정확하게 어딘지 안다는 뜻
        if (cnt == n - 1) answer++;
    }
    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    cout << solution(n, results);
    return 0;
}
