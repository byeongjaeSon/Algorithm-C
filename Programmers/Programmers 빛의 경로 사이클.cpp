#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool visited[500][500][4];
vector<string> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int changeDirection(char ch, int direction) {
    if (ch == 'L') {
        if (direction == 0) return 3;
        else if (direction == 1) return 0; 
        else if (direction == 2) return 1;
        else return 2;
    }
    
    if (direction == 0) return 1;
    else if (direction == 1) return 2; 
    else if (direction == 2) return 3;
    else return 0;
}

int simulate(int y, int x, int direction, int len) {
    if (visited[y][x][direction]) return len;
    
    visited[y][x][direction] = true;
    
    int nextDir = direction;
    if (board[y][x] != 'S') nextDir = changeDirection(board[y][x], direction);
    int nextY = y + dy[nextDir];
    int nextX = x + dx[nextDir];
    
    if (nextY < 0) nextY = n-1;
    if (nextX < 0) nextX = m-1;
    if (nextY >= n) nextY = 0;
    if (nextX >= m) nextX = 0;
       
    return simulate(nextY, nextX, nextDir, len+1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    n = grid.size();
    m = grid[0].size();
    board = grid;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int cycleLen = simulate(i, j, k, 0);
                if (cycleLen != 0) answer.push_back(cycleLen);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
