#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0 ,-1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> board(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	vector<vector<int>> visited(n, vector<int>(n));
	// bfs로 국경을 여는 애들 1로 만들고 set에 넣어 가면서 총합 더해가면서
	// queue empty 되면 set에 있는 애들 x,y 가져와서 총합이랑 set.size() 나눠서 x,y에 저장해
	int cnt = 0;
	while(1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				visited[i][j] = 0;
			}
		}
		int found = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j]){
					int sum = 0;
					queue<pair<int, int>> q;
					vector<pair<int, int>> s;
					s.clear();
					sum += board[i][j];
					q.push({i, j});
					s.push_back({i, j});
					visited[i][j] = 1;
					while(!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for(int dir = 0; dir< 4; dir++){
							int nx = x + dx[dir];
							int ny = y + dy[dir];
							if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1 || visited[nx][ny])
								continue;
							if(abs(board[nx][ny] - board[x][y]) >= l && abs(board[nx][ny] - board[x][y]) <= r){
								sum += board[nx][ny];
								q.push({nx, ny});
								s.push_back({nx, ny});
								visited[nx][ny] = 1;
							}
						}
					}
					if(s.size() >= 2) {
						found = 1;
					}
					sum = sum / s.size();
					for(int k = 0; k < s.size(); k++){
						board[s[k].first][s[k].second] = sum;
					}
				}
			}
		}
		if(found == 0){
			cout << cnt;
			break;
		}
		else cnt++;

	}
	return 0;
}
