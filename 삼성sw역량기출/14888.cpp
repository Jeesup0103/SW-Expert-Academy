#include <iostream>
#include <vector>
using namespace std;

int calcs[4];
int maximus = -2000000000, minimus = 2000000000;
int n;
vector<int> nums;

void calculate(int used, int result){
	if(used == n-1){
		maximus = max(maximus, result);
		minimus = min(minimus, result);
		return;
	}
	for(int i = 0; i < 4; i++){
		if(calcs[i] > 0){
			calcs[i]--;
			if(i == 0)
				calculate(used+1, result + nums[used+1]);
			else if(i == 1)
				calculate(used+1, result - nums[used+1]);
			else if(i == 2)
				calculate(used+1, result * nums[used+1]);
			else if(i == 3)
				calculate(used+1, result / nums[used+1]);
			calcs[i]++;
		}
	}
	return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	nums.resize(n);

	for(int i = 0; i < n ;i++){
		cin >> nums[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> calcs[i];
	}

	calculate(0, nums[0]);
	cout << maximus << "\n" << minimus;

	return 0;
}