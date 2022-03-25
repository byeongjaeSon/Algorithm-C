#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    
    unordered_map<string, string> um;
    vector<string> answer;
    
    for (string& r : record) {
        vector<string> log;
        stringstream ss(r);
        string temp;
        
        while (getline(ss, temp, ' ')) 
            log.push_back(temp);
        
        string cmd = log[0];
        string uid = log[1];
        string nickname = um[uid];
        if (cmd != "Leave")
            nickname = log[2];
        
        if (cmd == "Enter")
        {
            um[uid] = nickname;
            answer.push_back(uid + "님이 들어왔습니다.");
        }
        else if (cmd == "Leave")
        {
            answer.push_back(uid + "님이 나갔습니다.");
        }
        else 
        {
            um[uid] = nickname;
        }
            
    }
    
    for (string& ans : answer) 
    {
        int pos = ans.find("님");
        string uid = ans.substr(0, pos);
        ans.replace(0, uid.length(), um[uid]);
    }
    
    return answer;
}