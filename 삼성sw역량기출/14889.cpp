#include <iostream>
#include <vector>
using namespace std;
int score[21][21];
int n;
int minVal = 987654321;
vector<int> stored(21);

void calculate(){
	int val1 = 0;
	int val2 = 0;
	for(int i = 0; i < stored.size()-1; i++){
		for(int j = i + 1; j < stored.size(); j++){
			if(stored[i] == 1 && stored[j] == 1){
				val1 += score[i][j] + score[j][i];
			}
			else if(stored[i] == 0 && stored[j] == 0){
				val2 += score[i][j] + score[j][i];
			}
		}
	}
	int diff = abs(val1 - val2);
	minVal = min(diff, minVal);
	return;
}


void backtrack(int cnt, int idx){
	if(cnt == n/2){
		calculate();
	}
	for(int i = idx; i < n; i++){
		stored[i] = 1;
		backtrack(cnt+1, i+1);
		stored[i] = 0;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;

	for(int i = 0; i < n ;i++){
		for(int j = 0; j < n; j++){
			cin >> score[i][j];
		}
	}

	backtrack(0, 0);
	cout << minVal;

	return 0;
}