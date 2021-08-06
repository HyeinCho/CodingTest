#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    if(n <= 2) return n;
    
    int answer = 2;
    int sum = 0;
    
    vector<int> left_dp(n);
    vector<int> right_dp(n);
    
    left_dp[0] = a[0];
    for(int i=1;i<n;i++){
        if(left_dp[i-1] > a[i]) left_dp[i] = a[i];
        else left_dp[i] = left_dp[i-1];
    }
    
    right_dp[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(right_dp[i+1] > a[i]) right_dp[i] = a[i];
        else right_dp[i] = right_dp[i+1];
    }
    
    for(int i=1;i<a.size()-1;i++){
        int left = left_dp[i-1];
        int right = right_dp[i+1];
        
        if(a[i] > left && a[i] > right) continue;
        answer++;
    }
    
    return answer;
}
