#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[8][8];
vector<pair<int, int>> cctv;
int n, m;
int ans = 0;
// 하, 우, 상, 좌
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void scan(int dir, int x, int y){
	dir = dir%4;
	while(1){
		if(x < 0 || x > n-1 || y < 0 || y > m-1 || map[x][y] == 6)
			break;
		if(map[x][y] == 0){
			map[x][y] = -1;
		}
		x += dx[dir];
		y += dy[dir];
	}
	return;
}

void setcctv(int dir, int x, int y){
	if(map[x][y] == 1){
		// 하, 우, 상, 좌
		scan(dir, x, y);
	}
	else if(map[x][y] == 2){
		scan(dir, x, y);
		scan(dir+2, x, y);
	}
	else if(map[x][y] == 3){
		scan(dir, x, y);
		scan(dir+1, x, y);
	}
	else if(map[x][y] == 4){
		scan(dir, x, y);
		scan(dir+1, x, y);
		scan(dir+2, x, y);
	}
	else if(map[x][y] == 5){
		scan(dir, x, y);
		scan(dir+1, x, y);
		scan(dir+2, x, y);
		scan(dir+3, x, y);
	}
	return;
}

void backtrack(int used){
	if(used == cctv.size()){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(map[i][j] == 0)
					cnt++;
			}
		}
		ans = min(cnt, ans);
		return;
	}

	// save original board
	int orgBoard[8][8];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			orgBoard[i][j] = map[i][j];
		}
	}

	// Go through cctvs
	for(int i = 0; i < 4; i++){
		setcctv(i, cctv[used].first, cctv[used].second);
		//next cctv
		backtrack(used+1);
		//reset map
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				map[j][k] = orgBoard[j][k];
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j]>=1 && map[i][j] <= 5)
				cctv.push_back({i,j});
			else if(map[i][j] == 0)
				ans++;
		}
	}
	backtrack(0);

	cout << ans;


	return 0;
}
