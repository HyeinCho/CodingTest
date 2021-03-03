#include <string>
#include <vector>
#define INF 20000001

using namespace std;

// 플로이드 와샬
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
