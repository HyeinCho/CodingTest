#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> splitInfo(string s){
    vector<string> v;
    string tmp = "";
    for(char c : s){
        if(c == ' '){
            v.push_back(tmp);
            tmp = "";
        }
        else{
            tmp += c;
        }
    }
    v.push_back(tmp);
    if (v[0] == "Leave") v.push_back("");
    
    return v;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>> recordCopy;
    for(string s : record){
        vector<string> tmp = splitInfo(s);
        recordCopy.push_back(tmp);
        if(tmp[0] != "Leave"){
            m[tmp[1]] = tmp[2];
        }
    }
    
    for(vector<string> v : recordCopy){
        if(v[0] == "Enter"){ 
            answer.push_back(m[v[1]]+"님이 들어왔습니다.");
        }else if(v[0] == "Leave"){
            answer.push_back(m[v[1]]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}
