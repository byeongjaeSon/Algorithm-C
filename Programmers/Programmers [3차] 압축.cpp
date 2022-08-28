#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> word_to_index;

vector<int> solution(string msg) {
    vector<int> answer;
    int index = 1;
    while (index < 27) {
        word_to_index[string(1, 'A' + index - 1)] = index;
        index++;
    }
    
    for (int pos = 0; pos < msg.length(); ) {
        int max_cnt = 1;
        for (int cnt = 1; pos + cnt <= msg.length(); cnt++) {
            string key = msg.substr(pos, cnt);
            if (word_to_index.find(key) != word_to_index.end()) {
                max_cnt = cnt;
            }
        }
        string w = msg.substr(pos, max_cnt);
        answer.push_back(word_to_index[w]);
        if (pos + max_cnt < msg.length()) {
            word_to_index[msg.substr(pos, max_cnt+1)] = index++;
        }
        pos += max_cnt;
    }
    
    return answer;
}
