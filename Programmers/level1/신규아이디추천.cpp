#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1,2,3,4
    string tmp = "";
    for(int i=0;i<new_id.size();i++){
        char c = new_id[i];
        if (c >= 'a' && c <= 'z') tmp += c;
        else if(c >= 'A' && c <= 'Z'){
            tmp += c - 'A' + 'a';
        }else if(c >= '0' && c <= '9') tmp += c;
        else if(c == '-' || c == '_') tmp += c;
        else if(c == '.'){
            if(tmp.size() == 0 || i == new_id.size()-1) continue;
            else if(tmp.back() != '.') tmp += c;
        }
    }
    if(tmp.back() == '.') tmp.pop_back();
    
    // 5, 6, 7
    if(tmp.size() == 0) tmp = "aaa";
    else if(tmp.size() <= 2){
        while(tmp.size() < 3){
            tmp += tmp.back();
        }
    }
    else if (tmp.size() >= 16){
        tmp = tmp.substr(0, 15);
        if(tmp.back() == '.') tmp.pop_back();
    }
    
    return tmp;
}
