#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
set<string> st;
vector<vector<char>> board(4, vector<char>(4,' '));

void dfs(int x, int y, string seven){
    seven += board[x][y];
    if(seven.length() == 7){
        st.insert(seven);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < 0 || nextX > 4-1 || nextY < 0 || nextY > 4-1) continue;
        dfs(nextX, nextY, seven);
    }
    return;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int T;
    cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                char n;
                cin >> n;
                board[i][j] = n;
            }
        }
        st.clear();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                string init;
                dfs(i, j, init);
            }
        }
        cout << "#" << test_case << " " << st.size() << "\n";
	}
	return 0;
}
