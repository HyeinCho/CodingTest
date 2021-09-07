#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(vector<int> a) {
    int answer = 0;
    
    map<int, int> cnt;
    for(int n : a){
        if(cnt.find(n) == cnt.end()) cnt[n] = 1;
        else cnt[n]++;
    }
    
    vector<pair<int,int>> numbers;
    for(auto iter=cnt.begin();iter!=cnt.end();iter++){
        numbers.push_back({iter->first, iter->second});
    }
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int i=0;i<numbers.size();i++){
        if(answer >= 2 * numbers[i].second) break;
        
        int num = numbers[i].first;        
        int idx = 0;
        vector<bool> save(a.size());
        
        int sum = 0;
        
        while(true){
            auto iter = find(a.begin() + idx, a.end(), num);
            if(iter == a.end()) {
                break;
            }
            
            int next_idx = iter - a.begin();
            if(next_idx > 0 && !save[next_idx - 1] && a[next_idx - 1] != a[next_idx] ){
                save[next_idx - 1] = save[next_idx] = true;
                sum++;
            }else if(next_idx < a.size() - 1 && a[next_idx + 1] != a[next_idx]){
                save[next_idx + 1] = save[next_idx] = true;
                sum++;
            }
            idx = next_idx + 1;
        }
        if(answer < sum * 2) answer = sum * 2;
    }
    
    
    return answer;
}
