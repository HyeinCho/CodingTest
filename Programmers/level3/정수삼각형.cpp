#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = triangle.size();
    vector<vector<int>> dp(n);
    dp[0].push_back(triangle[0][0]);
    
    for(int i=1;i<n;i++){
        dp[i].push_back(dp[i-1][0] + triangle[i][0]);
        for(int j=1;j<i;j++){
            dp[i].push_back(max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
        }
        dp[i].push_back(dp[i-1][i-1] + triangle[i][i]);
    }
    for(int i=0;i<n;i++){
        if(answer < dp[n-1][i]){
            answer = dp[n-1][i];
        }
    }
    
    return answer;
}
