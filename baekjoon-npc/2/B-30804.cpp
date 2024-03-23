#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> tang(n);
	int fruit[10] = {0};
    for(int i = 0; i < n ;i++){
        cin >> tang[i];
    }

	int lPoint = 0;
	int rPoint = 0;
	int cnt = 0;
	int ans = 0;

	while(rPoint < n){
		if(fruit[tang[rPoint]] == 0){
			cnt++;
			fruit[tang[rPoint]]++;
		}
		if(cnt <= 2){ 
			ans = max(ans, rPoint-lPoint+1);
			rPoint++;
			if(rPoint < n && fruit[tang[rPoint]] != 0)
				fruit[tang[rPoint]]++;
		}
		else{
			fruit[tang[lPoint]]--;
			if(fruit[tang[lPoint]] == 0)
				cnt--;
			lPoint++;
		}
	}
	cout << ans;
	return 0;
}

/*
5
5 1 1 2 1

10
7 5 5 2 4 2 2 5 5 5

6
7 5 5 2 4 2
*/