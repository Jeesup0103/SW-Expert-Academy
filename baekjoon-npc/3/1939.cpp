#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>> map(10002);
int start, dest;
int n, m;

int bfs(){
	vector<int> carryMax(n+2, -1);
	priority_queue<pair<int, int>> pq;
	pq.push({1000000001, start});
	carryMax[start] = 1000000001;
	while(!pq.empty()){
		int curFactory = pq.top().second;
		int curEdge = pq.top().first;
		pq.pop();
		if(carryMax[curFactory] > curEdge)
			continue;
		for(int i = 0; i < map[curFactory].size(); i++){
			int nextFactory = map[curFactory][i].first;
			int carryWeight = min(map[curFactory][i].second, curEdge);
			// no edge
			if(carryWeight == 0)
				continue;
			if (carryMax[nextFactory] < carryWeight)
			{
				carryMax[nextFactory] = carryWeight;
				pq.push(make_pair(carryWeight, nextFactory));
			}
		}
	}
	return carryMax[dest];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n >> m;
	map.resize(n+2);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({b, c});
		map[b].push_back({a, c});
		// if(map[a][b] != 0){
		// 	int MM = max(map[a][b], c);
		// 	map[a][b] = MM;
		// 	map[b][a] = MM;
		// }
		// else{
		// 	map[a][b] = c;
		// 	map[b][a] = c;
		// }

	}
	cin >> start >> dest;

	cout << bfs();
}

/*

5 5
1 2 5
2 3 4
1 3 3
1 4 3
4 5 1
5 1
ans: 1

6 9
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
6 3
ans: 8

6 12
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
3 6 7
1 3 11
5 6 12
6 3
ans: 9

3 1
1 2 999999999
1 2
ans: 999999999

3 3
1 2 2
3 1 2
2 3 2
1 3
ans: 2

3 3
1 2 2
3 1 2
2 3 99999999
1 3
ans: 2
*/