#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
int garden[10][10];
int nutrition[10][10];
int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
vector<vector<vector<int>>> trees(10, vector<vector<int>>(10));

void springAndSummer(){
	vector<int> deadTrees;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int newNutrition = 0;
			// is tree in (i, j)
			if(trees[i][j].size() > 0){
				sort(trees[i][j].begin(), trees[i][j].end());
				for(int p = 0; p < trees[i][j].size(); p++){
					int age = trees[i][j][p];
					if(garden[i][j] >= age){
						garden[i][j] -= age;
						trees[i][j][p]++;
					}
					// die erase p'th element to end
					else{
						for (int m = p; m < trees[i][j].size(); m++) {
							newNutrition += trees[i][j][m]/2;
						}
						trees[i][j].erase(trees[i][j].begin() + p, trees[i][j].end());
					}
				}
			}
			if(newNutrition){
				garden[i][j] += newNutrition;
			}
		}
	}
	return;
}

void fall(){
	int newTree[10][10] = {0,};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(trees[i][j].size() > 0){
				for(int p = 0; p < trees[i][j].size(); p++){
					int age = trees[i][j][p];
					if(age % 5 == 0){
						// add nearby
						for(int dir = 0; dir < 8; dir++){
							int nx, ny;
							nx = i + dx[dir];
							ny = j + dy[dir];
							if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1) continue;
							newTree[nx][ny]++;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(newTree[i][j] > 0){
				int num = newTree[i][j];
				while(num--)
					trees[i][j].push_back(1);
			}
		}
	}
}

void winter(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			garden[i][j] += nutrition[i][j];
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m >>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> nutrition[i][j];
			garden[i][j] = 5;
		}
	}
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		trees[x-1][y-1].push_back(z);
	}

	while(k--){
		springAndSummer();
		fall();
		winter();
	}
	int alive = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!trees[i][j].empty()){
				alive += trees[i][j].size();
			}
		}
	}
	cout << alive;
	return 0;
}
