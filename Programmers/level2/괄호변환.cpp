#include <string>
#include <vector>
#include <stack>

using namespace std;

string recur(string s){
    if (s == "") return s;
    
    int tmp, idx;
    if(s[0] == '(') tmp = 1;
    else tmp = -1;
    for(int i=1;i<s.size();i++){
        if(s[i] == '(') tmp += 1;
        else tmp -= 1;
        
        if(tmp == 0) {
            idx = i+1;
            break;
        }
    }
    string u = s.substr(0, idx);
    string v = s.substr(idx);
    
    if(s[0] == '('){ // 정상
        return u + recur(v);
    }else{
        string tmp = "(";
        tmp += recur(v);
        tmp += ')';
        for(int i=1;i<u.size()-1;i++){
            if(u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
    
}

string solution(string p) {
    string answer = "";
    answer = recur(p);
    return answer;
}
