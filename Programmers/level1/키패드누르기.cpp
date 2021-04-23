#include <string>
#include <vector>

using namespace std;

pair<int, int> left = {3, 0};
pair<int, int> right = {3, 2};

char click(int number, string hand){
    if(number != 0 and number % 3 == 0){ // 오른쪽
        right = {number / 3 - 1, 2};
        return 'R';
    }else if(number % 3 == 1){ // 왼쪽
        left = {number / 3, 0};
        return 'L';
    }else{ // 중간
        int mid = number / 3;
        if(number == 0) mid = 3;
        int l = abs(left.first - mid) + abs(left.second - 1) ;
        int r = abs(right.first - mid) + abs(right.second - 1) ;
        
        if(l == r){
            if (hand == "left") {
                left = {mid, 1};
                return 'L';
            }
            else{
                right = {mid, 1};
                return 'R';
            }
        }else if (l < r){
            left = {mid, 1};
            return 'L';
        }else{
            right = {mid, 1};
            return 'R';
        }
    }
    
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int number : numbers){
        answer += click(number, hand);
    }
    return answer;
}
