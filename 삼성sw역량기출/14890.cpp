#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<vector<int>> map(100, vector<int>(100));
int checkRow(int row){
	int ret = 0;
	int flag = 1;

	vector<int> used(n,0);

	for(int i = 0; i < n-1; i++){
		int cur = map[row][i];
		int next = map[row][i+1];
		if(next == cur + 1){
			// search back if cnt of cur is bigger or same than len
			int tmp = i;
			int cnt = 1;
			if(used[tmp] == 1){
				flag = 0;
				break;
			}
			used[tmp] = 1;
			tmp--;
			while(cnt<l && tmp >= 0){
				if(used[tmp] == 1){
					flag = 0;
					break;
				}
				if(map[row][tmp] == cur){
					cnt++;
					used[tmp] = 1; // not mandatory
					tmp--;
				}
				else{
					break;
				}
			}
			// can go
			if(cnt >= l){
				continue;
			}
			else{
				flag = 0;
				break;
			}
		}
		else if(next == cur-1){
			// search front if cnt of cur is bigger or same than len
			int tmp = i+1;
			int cnt = 1;
			if(used[tmp] == 1){
				flag = 0;
				break;
			}
			used[tmp] = 1;
			tmp++;
			while(cnt<l && tmp < n){
				if(used[tmp] == 1){
					flag = 0;
					break;
				}
				if(map[row][tmp] == next){
					cnt++;
					used[tmp] = 1;
					tmp++;
				}
				else{
					break;
				}
			}
			// can go
			if(cnt >= l){
				continue;
			}
			else{
				flag = 0;
				break;
			}
		}
		else if(next == cur){
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		ret ++;
	}
	return ret;
}

int checkCol(int col){
	int ret = 0;
	int flag = 1;
	vector<int> used(n,0);

	for(int i = 0; i < n-1; i++){
		int cur = map[i][col];
		int next = map[i+1][col];
		if(next == cur + 1){
			// search back if cnt of cur is bigger or same than len
			int tmp = i;
			int cnt = 1;
			if(used[tmp] == 1){
				flag = 0;
				break;
			}
			used[tmp] =1;
			tmp--;
			while(cnt<l && tmp >= 0){
				if(used[tmp] == 1){
					flag = 0;
					break;
				}
				if(map[tmp][col] == cur){
					cnt++;
					used[tmp] = 1;
					tmp--;
				}
				else{
					break;
				}
			}
			// can go
			if(cnt >= l){
				continue;
			}
			else{
				flag = 0;
				break;
			}
		}
		else if(next == cur-1){
			// search front if cnt of cur is bigger or same than len
			int tmp = i+1;
			int cnt = 1;
			if(used[tmp] == 1){
				flag = 0;
				break;
			}
			used[tmp] = 1;
			tmp++;
			while(cnt<l && tmp < n){
				if(used[tmp] == 1){
					flag = 0;
					break;
				}
				if(map[tmp][col] == next){
					cnt++;
					used[tmp] = 1;
					tmp++;
				}
				else{
					break;
				}
			}
			// can go
			if(cnt >= l){
				continue;
			}
			else{
				flag = 0;
				break;
			}
		}
		else if(next == cur){
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}

	if(flag == 1){
		ret++;
	}
	return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> l;
	map.resize(n, vector<int>(n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}

	// check row
	int cnt =0;
	for(int i = 0; i < n; i++){
		cnt += checkRow(i);
		cnt += checkCol(i);
	}
	cout << cnt;

	return 0;
}
