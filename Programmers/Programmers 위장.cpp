#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
    
    for (vector<string>& cloth : clothes) {
        string clothType = cloth[1];
        um[clothType]++;
    }
    
    int answer = 1;
    for (unordered_map<string, int>::iterator iter = um.begin(); iter != um.end(); iter++) {
        answer *= (iter->second + 1);
    }
    answer--;
    
    return answer;
}