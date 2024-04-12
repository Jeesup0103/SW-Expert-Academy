#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m, h;
vector<vector<int>> ladder(31, vector<int>(11));
int found = 0;

bool check(){
	for(int i = 1; i <= n; i++){
		int col = i;
		for(int j = 1; j <= h; j++){
			// 1번째 세로선부터
			if(ladder[j][col] == 1) // go right
				col++;
			else if(ladder[j][col-1] == 1) // go left
				col--;
		}
		if(col != i) return false;
	}
	return true;
}

void solve(int maxdepth, int cnt){
	if(cnt >= 4) return;
	// check
	if(maxdepth == cnt)
	{
		if(check() == true){
			cout << maxdepth;
			exit(0);
		}
	}

	// find possible
	for(int j=1;j<n;j++) {
		for(int i=1;i<=h;i++) {
			if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
			ladder[i][j] = 1;
			solve(maxdepth,cnt+1);
			ladder[i][j] = 0;

			while(i<=h && !ladder[i][j-1] && !ladder[i][j+1]) i++;  
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m >> h;
	for(int i = 0; i < m ;i++){
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	for(int i = 0; i < 4; i++){
		solve(i, 0);
	}
	if(found == 0)
		cout << "-1";
	return 0;
}
