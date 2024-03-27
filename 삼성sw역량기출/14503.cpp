#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> room(51, vector<int>(51));

int dx[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int cnt = 0;
int n, m, a, b, dir, i, j;

void go(pair<int, int> cur, int dir){
	int canGo = 0;
	if(room[cur.first][cur.second] == 0){
		//clean
		cnt++;
		room[cur.first][cur.second] = 2;
	}
	// search
	int nextDir;
	pair<int, int> next;
	for(i = 3; i >= 0; i--){
		nextDir = (dir + i) % 4;
		next = {cur.first + dx[nextDir][0], cur.second + dx[nextDir][1]};
		if(next.first < 0 || next.first > n-1 || next.second < 0 || next.second > m-1 || 
			room[next.first][next.second] == 1 || room[next.first][next.second] == 2)
			continue;
		else{
			canGo = 1;
			break;
		}
	}
	if(canGo){
		go(next, nextDir);
	}
	else{
		pair<int, int> back;
		back.first = cur.first - dx[dir][0];
		back.second = cur.second - dx[dir][1];
		if(room[back.first][back.second] == 1)
			return;
		else{
			go(back, dir);
		}
	}

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;
	pair<int, int> start;
	cin >> a >> b;
	start = {a, b};
	cin >> dir;

	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			cin >> room[i][j];
		}
	}

	pair<int, int> cur;
	cur.first = start.first;
	cur.second = start.second;
	go(cur, dir);

	cout << cnt;

	return 0;
}


/*
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
*/