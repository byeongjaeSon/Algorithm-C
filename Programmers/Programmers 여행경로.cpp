#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;

bool findPath(vector<vector<string>>& tickets, vector<string>& path, vector<bool>& used) {
    
    if (path.size() == tickets.size()+1) {
        answer = path;
        return true;
    }
    
    vector<pair<string,int>> destinations;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == path.back() && !used[i]) 
            destinations.push_back({tickets[i][1], i});
    }
    sort(destinations.begin(), destinations.end());
    
    for (pair<string, int>& destInfo : destinations) {
        path.push_back(destInfo.first);
        used[destInfo.second] = true;
        if (findPath(tickets, path, used)) return true;
        path.pop_back();
        used[destInfo.second] = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> path = {"ICN"};
    vector<bool> used(tickets.size(), false);
    findPath(tickets, path, used);
    return answer;
}
