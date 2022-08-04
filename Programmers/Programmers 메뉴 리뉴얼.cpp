#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void pickMenu(string& order, int& foodCnt, int i, unordered_map<string, int>& pickedInfo, string pickedMenu) {
    
    if (pickedMenu.size() == foodCnt) {
        sort(pickedMenu.begin(), pickedMenu.end());
        pickedInfo[pickedMenu]++;
        return;
    }
    
    if (order.size() <= i) return;
    
    pickMenu(order, foodCnt, i+1, pickedInfo, pickedMenu);
    pickMenu(order, foodCnt, i+1, pickedInfo, pickedMenu + order[i]);
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int& foodCnt : course) {
        unordered_map<string, int> pickedInfo = {};
        for(string& order : orders) {
            pickMenu(order, foodCnt, 0, pickedInfo, "");
        }    
        if (pickedInfo.empty()) continue;
        
        vector<pair<string,int>> tempVec(pickedInfo.begin(), pickedInfo.end());
        sort(tempVec.begin(), tempVec.end(), cmp);
        
        int orderMaxCnt = tempVec[0].second;
        if (orderMaxCnt < 2) continue;
        for (pair<string, int>& orderInfo : tempVec) {
            if (orderInfo.second == orderMaxCnt)
                answer.push_back(orderInfo.first);
        }   
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
