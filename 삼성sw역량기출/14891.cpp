#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> gear(4);	
vector<int> pointer(4, 0);
vector<int> temp(4, 0);

int getRightPointer(int ptr){
	if(ptr > 5)
		return ptr - 6;
	return ptr + 2;
}

int getLeftPointer(int ptr){
	if(ptr < 2)
		return ptr + 6;
	return ptr - 2;
}


void turn(int num, int dir){
	int curTurn = dir;
	//check right
	for(int i = num; i < 3; i++){
		int curGearRight = getRightPointer(pointer[i]);
		int rightGearLeft = getLeftPointer(pointer[i+1]);

		// no turn
		if(gear[i][curGearRight] == gear[i+1][rightGearLeft])
			break;
		// right gear turn
		else{
			// right gear turn anti-clock
			if(curTurn == 1){
				temp[i+1] = (pointer[i+1] + 1) % 8;
				curTurn = -1;
			}
			else{
				temp[i+1] = (pointer[i+1] - 1) % 8;
				if(temp[i+1]< 0)
					temp[i+1] += 8;
				curTurn = 1;
			}
		}
	}
	curTurn = dir;
	// check left
	for(int i = num; i > 0; i--){
		int curGearLeft = getLeftPointer(pointer[i]);
		int leftGearRight = getRightPointer(pointer[i-1]);

		// no turn
		if(gear[i][curGearLeft] == gear[i-1][leftGearRight])
			break;
		// left gear turn
		else{
			// left geat turn anti-clock
			if(curTurn == 1){
				temp[i-1] = (pointer[i+1] + 1) % 8;
				curTurn = -1;
			}
			else{
				temp[i-1] = (pointer[i+1] - 1) % 8;
				if(temp[i-1]< 0)
					temp[i-1] += 8;
				curTurn = -1;
			}
		}
	}
	// anti-clock wise
	if(dir == -1){
		temp[num] = (pointer[num] + 1) % 8;
	}
	else{
		temp[num] = (pointer[num] - 1);
		if(temp[num]< 0)
			temp[num] += 8;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	for(int i = 0; i < 4; i++){
		cin >> gear[i];
	}

	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int num, dir;
		cin >> num >> dir;
		temp=pointer;
		turn(num-1, dir);
		pointer = temp;
	}

	int ans = 0;
	for(int i = 0; i < 4; i++){
		int num = gear[i][pointer[i]] - '0';
		ans += num*pow(2, i);
	}
	cout << ans;

	return 0;
}
