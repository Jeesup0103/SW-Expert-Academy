#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n;
int ans;
pair<int, int> house;
vector<pair<int, int>> client(10, {0, 0});
vector<int> visited(10, 0);

void dfs(int x, int y, int length, int dist){
    if(dist >= ans) return;
    if(length == n){
        dist = dist + abs(x -house.first) + abs(y - house.second);
        if(dist < ans){
            ans = dist;
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            int nextX = client[i].first;
            int nextY = client[i].second;
            int tempDist = dist + abs(x - nextX) + abs(y - nextY);
            dfs(nextX, nextY, length+1,tempDist);
            visited[i] = 0;
        }
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
        ans = 987654321;
        cin >> n;
        pair<int, int> comp;
        for(int i = 0; i < n ;i++){
            visited[i] = 0;
        }

        cin >> comp.first >> comp.second >> house.first >> house.second;
        for(int i = 0; i < n; i++){
            cin >> client[i].first >> client[i].second;
        }
        dfs(comp.first, comp.second, 0, 0);
        cout << "#" << test_case << " " << ans<< "\n";
	}
	return 0;
}
