// 슬라이딩 윈도우
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    set<string> s;
    for(string gem : gems) s.insert(gem);
    
    unordered_map<string, int> m;
    
    int mini = 100001;
    int start = 0;
    int end = 0;
    while (1){    
        // end
        // 모든 다이아를 포함하는 최소 index
        bool flag = false;
        for(int i=end;i<gems.size();i++){
            if (m.find(gems[i]) == m.end()) m[gems[i]] = 1;
            else m[gems[i]]++;
            
            if(m.size() == s.size()) {
                end = i;
                flag = true;
                break;
            }
        }
        
        // 찾아도 모든 다이아를 포함 못하므로 break
        if(!flag) break;
        
        // start
        // 모든 다이아를 포함하되 길이가 최소까지 될 수 있을 정도로
        for(int i=start;i<gems.size();i++){
            if (m[gems[i]] == 1){
                start = i;
                break;
            }else{
                m[gems[i]]--;
            }
        }
        
        if(end - start + 1 < mini){
            mini = end - start + 1;
            answer = {start+1, end+1};
        }
        m.erase(gems[start]);
        start++;
        end++;
    }
    
    return answer;
}
