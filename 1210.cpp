#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int solve(vector<vector<int>> board, pair<int, int> dest){
    pair<int, int>cur;
    cur = dest;
    while(cur.first > 0){
        //left is 1
        if(cur.second != 0 && board[cur.first][cur.second -1] == 1) 
        {
            board[cur.first][cur.second -1] = 0;
            cur.second--;
            continue;
        }
        //right is 1
        else if(cur.second != 99 && board[cur.first][cur.second +1] == 1) 
        {
            board[cur.first][cur.second +1] = 0;
            cur.second++;
            continue;
        }
         //up is 1
        else if(cur.first != 0 && board[cur.first-1][cur.second] == 1)
        {
            board[cur.first-1][cur.second] = 0;
            cur.first--;
            continue;
        }
    }
    return cur.second;
}

int main(){
    int T;
    T = 10;

    for(int testCase = 0; testCase < T; testCase++)
    {
        pair<int, int> dest;
        int n;
        cin >> n;

        vector<vector<int>> board(100, vector<int>(100, 0));
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                int m;
                cin >> m ;
                board[i][j] = m;
                if(board[i][j] == 2){
                    dest.first = i;
                    dest.second = j;
                }
            }
        }

        int ans = solve(board, dest);

        cout << "#" << testCase+1 << " " << ans << "\n";
    }
}
