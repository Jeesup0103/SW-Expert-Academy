#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> map(101,vector<int>(101));


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int r, c, k;
	cin >> r >> c >> k;
	r--;
	c--;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}
	int rsize = 3;
	int csize = 3;
	int found = 0;
	for(int p = 0; p <= 100; p++){
		if(map[r][c] == k){
			found = 1;
			cout << p;
			break;
		}
		if(rsize >= csize){
			// R 
			for(int i = 0; i < rsize; i++){
				vector<pair<int, int>> numCount(101);
				for(int p = 1; p < 101; p++){
					numCount[p].first = 0; // count
					numCount[p].second = p; // number
				}
				// calculate count of numbers
				for(int j = 0; j < csize; j++){
					if(map[i][j] == 0)
						continue;
					numCount[map[i][j]].first++;
				}
				sort(numCount.begin(), numCount.end());
				int idx = 0;
				for(int j = 0; j < 101; j++){
					if(numCount[j].first == 0) continue;
					map[i][idx++] = numCount[j].second;
					map[i][idx++] = numCount[j].first;
				}
				csize = max(csize, idx);
				// 다 0으로 채워?
				for(;idx<100;idx++){
					map[i][idx] = 0;
				}
			}
		}
		else{
			// R 
			for(int i = 0; i < csize; i++){
				vector<pair<int, int>> numCount(101);
				for(int p = 1; p < 101; p++){
					numCount[p].first = 0; // count
					numCount[p].second = p; // number
				}
				// calculate count of numbers
				for(int j = 0; j < rsize; j++){
					if(map[j][i] == 0)
						continue;
					numCount[map[j][i]].first++;
				}
				sort(numCount.begin(), numCount.end());
				int idx = 0;
				for(int j = 0; j < 101; j++){
					if(numCount[j].first == 0) continue;
					if(idx > 100) break;
					map[idx++][i] = numCount[j].second;
					map[idx++][i] = numCount[j].first;
				}
				rsize = max(rsize, idx);
				// 다 0으로 채워?
				for(;idx<100;idx++){
					map[idx][i] = 0;
				}
			}
		}
	}
	if(found == 0)
		cout << "-1";

	return 0;
}
