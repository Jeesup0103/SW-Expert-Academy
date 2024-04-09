#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 987654321
using namespace std;

int reduceTime[4] = {10, 60, 600, 30};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string inpt;
	cin >> inpt;
	string minute = "";
	string second = "";
	int wantTime = 0;
	for(int i = 0; i < inpt.size(); i++){
		if(i == 0 || i == 1){
			minute += inpt[i];
		}
		else if (i == 3 || i == 4){
			second += inpt[i];
		}
	}
	int required = stoi(minute) * 60 + stoi(second);
	vector<int> time(required+1, MAX);
	int ans = MAX;
	
	//남은 시간, 누른 횟수
	queue<pair<pair<int, int>, int>> q;
	q.push({{required, 0}, 0});

	while(!q.empty()) {
		int leftTime = q.front().first.first;
		int cnt = q.front().first.second;
		int started = q.front().second;
		q.pop();

		if(leftTime == 0){
			int tmp;
			if(started == 0)
				tmp = cnt+1;
			else
				tmp = cnt;
			ans = min(tmp, ans);
		}

		for(int i = 0; i < 4; i++){
			int nextLeftTime = leftTime - reduceTime[i];
			if(nextLeftTime < 0) continue;
			if(time[nextLeftTime] >= cnt+1){
				if(i == 3){
					// 시작 안누음
					if(started == 0){
						// 첫번째 버튼임
						if(cnt == 0){
							q.push({{nextLeftTime, cnt+1}, 1});
							time[nextLeftTime] = cnt+1;
						}
						else{
							q.push({{leftTime, cnt+1}, 1});
							time[leftTime] = cnt+1;
						}
					}
					else{
						q.push({{nextLeftTime, cnt+1}, 1});
						time[nextLeftTime] = cnt+1;
					}
				}
				else{
					q.push({{nextLeftTime, cnt+1}, started});
					time[nextLeftTime] = cnt+1;
				}
			}
		}
	}
	cout << ans;

}