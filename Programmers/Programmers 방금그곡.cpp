#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct Info {
    string title;
    int playTime;
    int order;
} Info;

const int mod = 127;
const int base = 256;
unordered_map<string, string> convertingMap;

vector<string> split(string& input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int rabin_hash(string s) {
	int ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % mod;
	}
	return ans;
}

bool rabin_karp(string &s, string &p) {
	int n = s.length(), m = p.length();
	if (n < m) return 0;	
	int hash_p = rabin_hash(p), hash_s = rabin_hash(s.substr(0, m));
	int first = 1;

	for (int i = 0; i< m - 1; i++) 
		first = (first * base) % mod;

	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) 
			if (s.substr(i, m) == p) return true;		
		
		if (i + m < n) {
			hash_s = hash_s - (s[i] * first) % mod;
			hash_s = (hash_s + mod) % mod;
			hash_s = ((hash_s * base) % mod + s[i + m]) % mod;
		}
	}
	return false;	
}

bool cmp(Info& a, Info& b) {
    if (a.playTime > b.playTime) return true;
    else if (a.playTime == b.playTime) {
        if (a.order < b.order) return true;
    }
    return false;
}

void convert(string& s) {
    for (auto iter : convertingMap) {
        while (1) {
            size_t pos = s.find(iter.first);
            if (pos == std::string::npos) {
                break;
            }
            s.replace(pos, iter.first.length(), iter.second);
        }
    }
}

string solution(string m, vector<string> musicinfos) {
    vector<Info> answerInfos;
    int order = 0;
    
    convertingMap["C#"] = "H";
    convertingMap["D#"] = "I";
    convertingMap["F#"] = "J";
    convertingMap["G#"] = "K";
    convertingMap["A#"] = "L";
    
    convert(m);
    
    for (string& musicinfo : musicinfos) {
        vector<string> splitResult= split(musicinfo, ',');
        string startTime_s = splitResult[0], endTime_s = splitResult[1], 
            title = splitResult[2], sheet = splitResult[3];
        
        vector<string> startTimeSplit = split(startTime_s, ':'), 
            endTimeSplit = split(endTime_s, ':');
        
        convert(sheet);
        
        int startTime = (stoi(startTimeSplit[0]) * 60 + stoi(startTimeSplit[1])),
            endTime = (stoi(endTimeSplit[0]) * 60 + stoi(endTimeSplit[1])),
            playTime = endTime - startTime,
            share = playTime / sheet.length(),
            remain = playTime % sheet.length();
        
        string playedSheet = "";
        for (int i = 0; i < share; i++) {
            playedSheet += sheet;
        }
        for (int i = 0; i < remain; i++) {
            playedSheet += sheet[i];
        }
        
        if (rabin_karp(playedSheet, m)) {
            answerInfos.push_back({title, playTime, order++});
        }  
     }
    
    if (answerInfos.empty()) return "(None)";

    sort(answerInfos.begin(), answerInfos.end(), cmp);
    return answerInfos[0].title;    
}
