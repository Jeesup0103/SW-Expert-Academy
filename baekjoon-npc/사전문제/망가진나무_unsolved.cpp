#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#define MAXNUM 999999
using namespace std;

typedef struct Node{
    int vertex;
    int idx;
    bool inverted;
}Node;

vector<vector<Node>> graph(MAXNUM, vector<Node>());
vector<bool> visited(MAXNUM);
int temp[MAXNUM];
int M = MAXNUM;
int fin;
string ans;

int traverse(int n) {
    visited[n] = true; 
    int ret = 0;
    for(int i = 0; i < graph[n].size(); i++) {
        int nextV = graph[n][i].vertex;
        if(!visited[nextV]) {
            ret += traverse(nextV) + graph[n][i].inverted;
        }
    }
    return ret;
}

void secondTrav(int from, int to, bool inv)
{
	visited[to] = 1;
	if (inv) temp[to] = temp[from] - 1;
	else temp[to] = temp[from] + 1;

	for (int i = 0; i < graph[to].size(); i++){
		if (!visited[graph[to][i].vertex]) 
            secondTrav(to, graph[to][i].vertex, graph[to][i].inverted);
    }
}

void thirdTrav(int n)
{
	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++){
		if (!visited[graph[n][i].vertex])
		{
            int idx = graph[n][i].idx;
            bool flag = graph[n][i].inverted;
			ans[idx] = flag + '0';
			thirdTrav(graph[n][i].vertex);
		}
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    graph.resize(n+1, vector<Node>());
    visited.resize(n+1);
	ans.resize(n+1);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i, false});  
        graph[b].push_back({a, i, true});
    }

    int firstNode = 1;

    //first traversal    
    temp[1] = traverse(firstNode);

    //second traversal
    fill(visited.begin(), visited.end(), false);
    visited[1] = true;
    for (int i = 0; i < graph[1].size(); i++){
		secondTrav(1, graph[1][i].vertex, graph[1][i].inverted);
    }
	for (int i = 1; i <= n; i++){
        if (M > temp[i])
        {
            M = temp[i];
            fin = i;
        }
    }
    fill(visited.begin(), visited.end(), false);
	thirdTrav(fin);
	cout << ans;
	return 0;
}
