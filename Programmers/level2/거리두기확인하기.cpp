#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool check(pair<int, int> a, pair<int, int> b, vector<string> place){
    int dist = abs(a.first - b.first) + abs(a.second - b.second);
    if(dist > 2) return true;
    if(dist == 1) return false;
    
    // 같은 행
    if(a.first == b.first) {
        if(a.second < b.second){
            if(place[a.first][a.second + 1] == 'X') return true;
            else return false;
        }else{
            if(place[a.first][b.second + 1] == 'X') return true;
            else return false;
        }
    }
    
    // 같은 열
    if(a.second == b.second) {
        if(a.first < b.first){
            if(place[a.first + 1][a.second] == 'X') return true;
            else return false;
        }else{
            if(place[b.first + 1][a.second] == 'X') return true;
            else return false;
        }
    }
    
    // 대각선
    int x = min(a.first, b.first);
    int y = min(a.second, b.second);
    
    if(place[x][y] == 'O' || place[x+1][y] == 'O' || place[x][y+1] == 'O' || place[x+1][y+1] == 'O') return false;
    else return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    
    for(vector<string> place : places){
        vector<pair<int, int>> people;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j] == 'P') people.push_back({i, j});
            }
        }
        
        bool flag = false;
        for(int i=0;i<people.size();i++){
            for(int j=i+1;j<people.size();j++){
                if(!check(people[i], people[j], place)) {
                    answer.push_back(0);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) answer.push_back(1);
    }
    
    
    
    return answer;
}
