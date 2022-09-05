#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1) {
        set<pair<int,int>> s;
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n-1; j++) {
                
                if (board[i][j] == ' ') continue;
                
                vector<pair<int,int>> cmp_candidates = {{i, j+1}, {i+1, j}, {i+1, j+1}};
                
                bool isMatch = true;
                for (pair<int,int>& p : cmp_candidates) {
                    if (board[i][j] != board[p.first][p.second]){
                        isMatch = false;
                        break;
                    }
                }
                if (!isMatch) continue;
                
                s.insert({i,j});
                
                for (pair<int,int>& p : cmp_candidates) {
                    s.insert(p);
                } 
            }
        }
        
        for (auto e : s) {
            board[e.first][e.second] = ' ';
            int h = e.first;
            while (h > 0) {
                char tmp = board[h-1][e.second];
                board[h-1][e.second] = board[h][e.second];
                board[h][e.second] = tmp;
                h--;
            }
        }
        
        answer += s.size();
        if (s.empty()) break;
    }
    
    return answer;
}

