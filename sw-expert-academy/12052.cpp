#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int T;
    cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        vector<string> map;
        bool flag = false;
        int row;
        int col;
        cin >> row >> col;
        for(int i = 0; i < row; i++){
            string str;
            cin >> str;
            map.push_back(str);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(map[i][j] == '#'){
                    if(i == row-1 || j == col-1) continue;
                    if(map[i+1][j] == '#' && map[i][j+1] == '#' && map[i+1][j+1] == '#'){
                        map[i][j] = '.';
                        map[i+1][j] = '.';
                        map[i][j+1] = '.';
                        map[i+1][j+1] = '.';
                    }
                }
            }
        }
        for(int i = 0; i < row; i++){
            if(flag == true) break;
            for(int j = 0; j < col; j++){
                if(map[i][j] == '#')
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false)
            cout << "#" << test_case << " YES\n";
        else
            cout << "#" << test_case << " NO\n";
	}
	return 0;
}