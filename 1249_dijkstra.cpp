#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Cell {
    int x, y, cost;
    Cell(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool operator>(const Cell& other) const {
        return cost > other.cost;
    }
};

int main(int argc, char** argv)
{
	int T;
    cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int size;
		cin >> size; 
        string line;
        vector <vector<int>> map;
        for (int i = 0; i < size; ++i) {
            cin >> line;
            vector<int> row;

            for (char c : line) {
                row.push_back(c - '0');
            }
            map.push_back(row);
        }

        vector<vector<int>> cost(size, vector<int>(size, 987654321));
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        pq.push(Cell(0, 0, map[0][0]));
        cost[0][0] = 0;
        while(!pq.empty())
        {
            // pop the smallest obstacle in queue
            Cell current = pq.top();
            pq.pop();

            // found
            if(current.x == size-1 && current.y == size-1)
            {
                cout << "#" << test_case<<" "<< current.cost<< "\n";
                break;
            }

            
            for (int i = 0; i < 4; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];

                //if next is inside map
                if (newX < size && newY < size && newX >=0 && newY >= 0) {
                    // get new cost as current cost + next cost
                    int newCost = current.cost + map[newX][newY];
                    // if the new cost is smaller than the cost the it has on the cost table -> renew cost on cost table
                    if (newCost < cost[newX][newY]) {
                        cost[newX][newY] = newCost;
                        // push next in queue
                        pq.push(Cell(newX, newY, newCost));
                    }
                }
            }
        }
        
	}
	return 0;
}