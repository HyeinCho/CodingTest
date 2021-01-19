#include <string>
#include <vector>

using namespace std;

int answer = 0;

void go(int idx, int sum, vector<int> numbers, int target){
    if(idx == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    go(idx + 1, sum + numbers[idx], numbers, target);
    go(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    go(0, 0, numbers, target);
    return answer;
}
