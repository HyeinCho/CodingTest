#include <string>
#include <vector>

using namespace std;

int arr[101][101];

int rotate(vector<int> query) {
    int r1 = query[0];
    int c1 = query[1];
    int r2 = query[2];
    int c2 = query[3];
    
    int mini = arr[r1][c1];
    int tmp = arr[r1][c1];
    
    for(int i=r1;i<r2;i++) {
        arr[i][c1] = arr[i+1][c1];
        if(mini > arr[i][c1]) mini = arr[i][c1];
    }
    for(int i=c1;i<c2;i++) {
        arr[r2][i] = arr[r2][i+1];
        if(mini > arr[r2][i]) mini = arr[r2][i];
    }
    for(int i=r2;i>r1;i--) {
        arr[i][c2] = arr[i-1][c2];
        if(mini > arr[i][c2]) mini = arr[i][c2];
    }
    for(int i=c2;i>c1;i--) {
        if(mini > arr[r1][i]) mini = arr[r1][i];
        arr[r1][i] = arr[r1][i-1];
    }
    arr[r1][c1+1] = tmp;
    
    return mini;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++) arr[i][j] = num++;
    }
    
    for(vector<int> query : queries) {
        answer.push_back(rotate(query));
    }
    
    return answer;
}
