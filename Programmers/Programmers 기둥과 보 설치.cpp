#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101][2];
int N;

bool install_item(int x, int y, int a) {
    if(a == 0) { // 기둥 설치
        if(y == 0) return true; // 바닥위에 있거나
        if(x > 0 && arr[x-1][y][1]) return true; // 보의 오른쪽 끝 위
        if(y < N && arr[x][y][1]) return true; // 보의 왼쪽 끝 위
        if(y > 0 && arr[x][y-1][0]) return true; // 다른 기둥 위
    }
    else { // 보 설치
        if(y > 0 && arr[x][y-1][0]) return true; // 왼쪽 끝 아래 기둥
        if(x < N && y > 0 && arr[x+1][y-1][0]) return true; // 오른쪽 끝 아래 기둥
        if(x > 0 && x < N && arr[x-1][y][1] && arr[x+1][y][1]) return true; // 양쪽 끝 부분 다른 보
    }
    return false;
}

bool remove_item(int x, int y, int a) {
    arr[x][y][a] = 0;
    
    if(a == 0) { // 기둥 삭제
        // 위에 기둥 있을 때, 설치 가능?
        if(y < N && arr[x][y+1][0] && !install_item(x, y+1, 0)) return false;
        
        // 위에 보 있을 때, 설치 가능?
        if(y < N && arr[x][y+1][1] && !install_item(x, y+1, 1)) return false;
        if(x > 0 && y < N && arr[x-1][y+1][1] && !install_item(x-1, y+1, 1)) return false;
    }
    else {
        // 위에 기둥 있을 때, 설치 가능?
        if(arr[x][y][0] && !install_item(x, y, 0)) return false;
        if(x < N && arr[x+1][y][0] && !install_item(x+1, y, 0)) return false;
        
        // 다른 보와 연결되어 있을 때, 설치 가능?
        if(x > 0 && arr[x-1][y][1] && !install_item(x-1, y, 1)) return false;
        if(x < N && arr[x+1][y][1] && !install_item(x+1, y, 1)) return false;
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    vector<vector<int>> answer;
    
    for(auto frame: build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];
        
        if(b == 0) {
            if(!remove_item(x, y, a)) arr[x][y][a] = 1;
        }
        else {
            if(install_item(x, y, a)) arr[x][y][a] = 1;
        }
    }
    
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=n; ++j) {
            if(arr[i][j][0]) answer.push_back({i, j, 0});
            if(arr[i][j][1]) answer.push_back({i, j, 1});
        }
    }
    
    return answer;
}
