#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(21, vector<int>(21));
vector<int> dice(6,0);
pair<int, int> cur;

int canMove(int move, int n, int m){
	if(move == 1 && cur.second != m-1){ // 동
		cur.second++;
		return 1;
	}
	else if(move == 2 && cur.second != 0) // 서쪽
	{
		cur.second--;
		return 1;
	}
	else if(move == 3 && cur.first != 0) // 북
	{
		cur.first--;
		return 1;
	}
	else if(move == 4 && cur.first != n-1)
	{
		cur.first++;
		return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); 
	cout.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	map.resize(n, vector<int>(m));
	cur.first = x;
	cur.second = y;

	// [0] 위, [1] 우, [2] 아래, [3] 좌, [4] 앞, [5] 뒤
	// 동 or 서 -> 0,1,2,3 오른쪽 or 왼쪽 shift
	// 남 or 북 -> 0,4,2,5 오른쪽 or 왼쪽 shift
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		int move;
		cin >> move;
		// 동
		if(canMove(move, n, m)){
			int shifting[4]; 
			if(move == 1 || move == 3){
				// shift right
				if(move == 1){
					shifting[0] = 0; shifting[1] = 1; shifting[2] = 2; shifting[3] = 3;
				}
				else{
					shifting[0] = 0; shifting[1] = 4; shifting[2] = 2; shifting[3] = 5;
				}
				int temp = dice[shifting[3]];
				for(int i = 3; i >0; i--){
					dice[shifting[i]] = dice[shifting[i-1]];
				}
				dice[shifting[0]] = temp;
			}
			else if(move == 2 || move == 4){
				// shift left
				if(move == 2){
					shifting[0] = 0; shifting[1] = 1; shifting[2] = 2; shifting[3] = 3;
				}
				else{
					shifting[0] = 0; shifting[1] = 4; shifting[2] = 2; shifting[3] = 5;
				}
				int temp = dice[shifting[0]];
				for(int i = 0; i < 3; i++){
					dice[shifting[i]] = dice[shifting[i+1]];
				}
				dice[shifting[3]] = temp;
			}
			int bottom = dice[2];
			if(map[cur.first][cur.second] == 0){
				map[cur.first][cur.second] = bottom;
			}
			else{
				dice[2] = map[cur.first][cur.second];
				map[cur.first][cur.second] = 0;
			}
			cout << dice[0] << "\n";
		}
	}
	return 0;

}

//주사위의 숫자를 잘 관리할 자료구조가 뭘까

/*
    _____
  / 1  / |
/_____/  |
|     |3 |
|   5 | /
|_____|/

*/


