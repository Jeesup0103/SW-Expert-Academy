#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>
using namespace std;
bool visited[50][50];
int DP[51][51];
int dx[4] = {-1, 1, 0, 0};   
int dy[4] = {0, 0, -1, 1};  
queue<pair<int,int> > q; 
vector<string> map(51);
int n, m;
int MM = -1;
int flag = 0;

int dfs(int x, int y){
	if(flag == 1)
		return 0;
	if(x < 0 || y < 0 || x > n-1 || y > m-1 || map[x][y] == 'H')
		return 0;
	// 방문한데 또 방문
	if(visited[x][y] == true){
		flag = 1;
		return -1;
	}
	if (DP[x][y] != -1) return DP[x][y];
	visited[x][y] = true;
	int val = map[x][y] - '0';
	for(int i = 0; i < 4; i++){
		int nx = x + val * dx[i];
		int ny = y + val * dy[i];
		DP[x][y] = max(DP[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;
	return DP[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n >> m;
	map.resize(n+1);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	memset(DP, -1, sizeof(DP));
	int ans = dfs(0, 0);
	if(flag == 1)
		cout << "-1";
	else
		cout << ans;
	return 0;
}