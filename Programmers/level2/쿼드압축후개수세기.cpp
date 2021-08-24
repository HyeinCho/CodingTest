#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void zip(int x, int y, int size, vector<vector<int>>& arr){
    if(size == 1){
        answer[arr[x][y]]++;
        return;
    }
    
    int num = arr[x][y];
    bool flag = true;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(num != arr[i][j]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag){
        answer[arr[x][y]]++;
    }else{
        zip(x, y, size / 2, arr);
        zip(x + size / 2, y, size / 2, arr);
        zip(x, y + size / 2, size / 2, arr);
        zip(x + size / 2, y + size / 2, size / 2, arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    zip(0,0, arr.size(), arr);
    return answer;
}
