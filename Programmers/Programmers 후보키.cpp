#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int colCnt = 0;

vector<vector<int>> candidateKeys;

bool isUnique(vector<vector<string>>& relation, vector<int>& options) {
    unordered_map<string, int> um;
    for (vector<string>& row : relation) {
        string key = "";
        for (int& option : options) {
            key += row[option];
        }
        if (++um[key] > 1) return false; 
    }
    return true;
}

bool isSubset(vector<int>& candidateKey, vector<int>& options) {
    for (int& col : candidateKey) {
        auto iter = find(options.begin(), options.end(), col);
        if (iter == options.end()) return false;
    }
    return true;
}

bool isMinimal(vector<int>& options) {
   for (vector<int>& candidateKey : candidateKeys) {
       if (isSubset(candidateKey, options)) return false;
   }
    return true;
}

void findCandidateKeyCnt(vector<vector<string>>& relation, int i, vector<int> options, int cntToPick) {
    
    if (options.size() == cntToPick) {
        if (isUnique(relation, options) && isMinimal(options)) {
            candidateKeys.push_back(options);                
        }
        return;
    }
    
    if (i >= colCnt) return;
    
    findCandidateKeyCnt(relation, i+1, options, cntToPick);
    options.push_back(i);
    findCandidateKeyCnt(relation, i+1, options, cntToPick);
}

int solution(vector<vector<string>> relation) {  
    colCnt = relation[0].size();
    for (int cntToPick = 1; cntToPick <= colCnt; cntToPick++) {
        findCandidateKeyCnt(relation, 0, {}, cntToPick);
    }
    return candidateKeys.size();
}
