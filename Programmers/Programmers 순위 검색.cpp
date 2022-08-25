#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

bool isMatch(const string& cond, string& candi) {
    for (int i = 0; i < candi.size(); i++) {
        if (candi[i] == '-') continue;
        if (cond[i] != candi[i]) return false;
    }
    return true;
} 

vector<string> split(string& input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    unordered_map<string, vector<int>> condToScores;
    
    for (string& supportData : info) {
        string cond = "";
        vector<string> result = split(supportData, ' ');
        for (int i = 0; i < result.size()-1; i++) {
            cond += result[i][0];
        }
        condToScores[cond].push_back(stoi(result.back()));
    }
    
    for (string& q : query) {
        string cond = "";
        vector<string> result = split(q, ' ');
        for (int i = 0; i < result.size()-1; i++) {
            if (result[i] == "and") continue;
            cond += result[i][0];
        }
        
        int threshold = stoi(result.back()), cnt = 0;
        for (auto& it : condToScores) {
          if (isMatch(it.first, cond)) {
              for (int& score : it.second) {
                  if (score >= threshold) cnt++;
              }
          }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
