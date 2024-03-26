#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> days(n+2);
	vector<int> profit(n+2, 0);
	int i;
	for(i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		days[i] = {a, b};
	}
	for(int i = n; i > 0; i--){
		int pos = i + days[i].first;
		if(pos > n + 1){
			profit[i] = profit[i+1];
		}
		else{
			profit[i] = max(profit[i+1], days[i].second + profit[pos]);
		}
	}
	cout << profit[1];
	

	return 0;
}


/*
n일 차의 최대 이익은 
n-1일 이익 + n일차 이익 (가능하다면)
또는
n-2일 이익 + n-1일차 이익
또는
n-3일 이익 + n-2일차 이익
또는
n-4일 이익 + n-3일차 이익


어떻게 하지?
...



*/