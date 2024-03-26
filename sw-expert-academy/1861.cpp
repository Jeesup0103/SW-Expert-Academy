#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;
int ansNum;

int dfs(int x, int y, vector<vector<int>> board, vector<vector<int>> visited, int size){
    if(visited[x][y] != 0) return visited[x][y];
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < 0 || nextX > size-1 || nextY < 0 || nextY > size-1) continue;
        if(board[nextX][nextY] == board[x][y] + 1){
            visited[x][y] = visited[x][y] + dfs(nextX, nextY, board, visited, size);
        }
    }
    return visited[x][y];
}

pair<int, int> solve(vector<vector<int>> board, vector<vector<int>> visited, int size){
    pair<int, int> sol;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++){
            int res = dfs(i, j, board, visited, size);
            if(ans < res){
                ans = res;
                ansNum = board[i][j];
            }
            else if(ans == res){
                ansNum = min(ansNum, board[i][j]);
            }
        }
    }
    sol.first = ans;
    sol.second = ansNum;
    return sol;
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

        int size;
        cin >> size;

        vector<vector<int>> board(size,vector<int>(size,0));
        vector<vector<int>> visited(size,vector<int>(size,0));
        for(int i = 0; i < size; i++)
        {
            for(int j =0; j < size; j++){
                int n;
                cin >> n;
                board[i][j] = n;
            }
        }
        pair<int, int> sol;
        sol = solve(board, visited, size);


        cout << "#" << test_case << " " << sol.second << " " << sol.first <<"\n";

	}
	return 0;
}