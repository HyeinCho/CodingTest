#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dp[2501][2501]; // dp[i][j]: i부터 j까지가 팰린드롬이 되는지 유무

int solution(string s)
{
    int answer=1; // 가장 작은 팰린드롬의 길이는 1
    for(int i=0;i<s.size();i++) {
        dp[i][i] = true;
        if (i<s.size()-1 && s[i] == s[i+1]) {
          dp[i][i+1] = true;
          answer = 2;
        }
    }
    
    for (int i=3;i<=s.size();i++){ // i: 길이
        for (int j=0;j<=s.size()-i;j++){
            if(s[j] == s[j+i-1] && dp[j+1][j+i-2]){
                dp[j][j+i-1]=true;
                answer = i;
            }    
        }
    }
    
    
    return answer;
}
