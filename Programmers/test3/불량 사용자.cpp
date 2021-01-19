#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<bool> visited;
set<string> result; 

bool isSame(string a, string b){
    if(a.size() != b.size()) return false;
    for(int i=0;i<a.size();i++){
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

void check(int idx, vector<string> tmp, vector<string> user_id, vector<string> banned_id){
    if(idx == banned_id.size()){
        sort(tmp.begin(), tmp.end());
        string s = "";
        for(string str : tmp) s += str;
        result.insert(s);
        return;
    }
    
    for(int i=0;i<user_id.size();i++){
        if(visited[i]) continue;
        if(isSame(user_id[i], banned_id[idx])){
            visited[i] = true;
            tmp.push_back(user_id[i]);
            check(idx+1, tmp, user_id, banned_id);
            visited[i] = false;
            tmp.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    visited.resize(user_id.size());
    check(0, {}, user_id, banned_id);
    answer = result.size();
    return answer;
}
