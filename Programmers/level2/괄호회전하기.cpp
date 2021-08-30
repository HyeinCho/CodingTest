#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.size();
    for(int i=0;i<n;i++){
        stack<char> q;
        bool flag = true;
        for(int j=i;j<n+i;j++){
            if(s[j % n] == '['){
                q.push('[');
            }else if(s[j % n] == '{'){
                q.push('{');
            }else if(s[j % n] == '('){
                q.push('(');
            }else if(s[j % n] == ']'){
                if(q.empty() || q.top() != '[') {
                    flag = false;
                    break;
                }else{
                    q.pop();
                }
            }else if(s[j % n] == '}'){
                if(q.empty() || q.top() != '{') {
                    flag = false;
                    break;
                }else{
                    q.pop();
                }
            }else{
                if(q.empty() || q.top() != '(') {
                    flag = false;
                    break;
                }else{
                    q.pop();
                }
            }
        }
        if(flag && q.empty()) answer += 1;
    }
    return answer;
}
