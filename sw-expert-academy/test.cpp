#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

int N;
int rooms[MAX_N][MAX_N];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};

struct Room {
    int x, y, number;
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

pair<int, int> bfs(int startX, int startY) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Room> q;
    q.push({startX, startY, rooms[startX][startY]});
    visited[startX][startY] = true;
    int maxCount = 1;
    int startNumber = rooms[startX][startY];

    while (!q.empty()) {
        Room current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY) && !visited[newX][newY] && rooms[newX][newY] == current.number + 1) {
                q.push({newX, newY, rooms[newX][newY]});
                visited[newX][newY] = true;
                maxCount++;
                startNumber = min(startNumber, rooms[newX][newY]);
            }
        }
    }

    return make_pair(startNumber, maxCount);
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> rooms[i][j];
            }
        }

        int maxRooms = 0;
        int startingRoom = MAX_N * MAX_N;

        // 각 방을 출발점으로 해서 bfs 수행
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                pair<int, int> result = bfs(i, j);
                if (result.second > maxRooms) {
                    maxRooms = result.second;
                    startingRoom = result.first;
                } else if (result.second == maxRooms) {
                    startingRoom = min(startingRoom, result.first);
                }
            }
        }

        cout << "#" << tc << " " << startingRoom << " " << maxRooms << endl;
    }

    return 0;
}
